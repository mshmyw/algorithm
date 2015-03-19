#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <errno.h>

#define PORT_SNMP 161
#define MAX_CONNECT_RETRY 1
#define WAIT_BETWEEN_CONNECT_RETRY 3

/* rfc 1928 SOCKS proxy */
#define SOCKS_V5	5
#define SOCKS_V4	4
#define SOCKS_NOAUTH	0

/* http://tools.ietf.org/html/rfc1929 */
#define SOCKS_PASSAUTH	2
#define SOCKS_NOMETHOD	0xff
#define SOCKS_CONNECT	1
#define SOCKS_IPV4	1
#define SOCKS_DOMAIN	3
#define SOCKS_IPV6	4

int waittime = 200;
char quiet;
int do_retry = 1;
int module_auth_type = -1;
int intern_socket, extern_socket;
char pair[260];
char HYDRA_EXIT[5] = "\x00\xff\x00\xff\x00";
char *HYDRA_EMPTY = "\x00\x00\x00\x00";
char *fe80 = "\xfe\x80\x00";
int fail = 0;
int alarm_went_off = 0;
int use_ssl = 0;
char ipaddr_str[64];
int src_port = 0;
int __fck = 0;
int ssl_first = 1;
int __first_connect = 1;
char ipstring[64];
unsigned int colored_output = 1;
char quiet = 0;

struct SNMPV1_A {
	char ID;
	char len;
	char ver[3];
	char comid;
	char comlen;
};

struct SNMPV1_A snmpv1_a = {
	.ID = '\x30',
	.len = '\x00',
	 .ver = "\x02\x01\x00",        /* \x02\x01\x01 for snmpv2c, \x02\x01\x03 for snmpv3 */
	.comid = '\x04',
	.comlen = '\x00'
};

struct SNMPV1_R {
	unsigned char type[2];
	unsigned char identid[2];
	unsigned char ident[4];
	unsigned char errstat[3];
	unsigned char errind[3];
	unsigned char objectid[2];
	unsigned char object[11];
	unsigned char value[3];
} snmpv1_r = {
	.type = "\xa0\x1b",           /* GET */
	.identid = "\x02\x04",.ident = "\x1a\x5e\x97\x00",  /* random crap :) */
	.errstat = "\x02\x01\x00",  /* no error */
	 .errind = "\x02\x01\x00",   /* error index 0 */
	.objectid = "\x30\x0d",.object = "\x30\x0b\x06\x07\x2b\x06\x01\x02\x01\x01\x01",    /* sysDescr */
	.value = "\x05\x00"         /* we just read, so value = 0 */
};


void alarming() {
	fail++;
	alarm_went_off++;
}

int internal__hydra_connect(char *host, int port, int protocol, int type) {
	int s, ret = -1;
	int bind_ok;
		
	struct sockaddr_in target;
	struct sockaddr_in sin;
	char *buf, *tmpptr = NULL;
	int err = 0;
	
	int src_port = 83;  //assume src port
	
	s = socket(PF_INET, protocol, type);
	if (s >= 0) {
		if (src_port != 0) {
			bind_ok = 0;
			
			sin.sin_family = PF_INET;
			sin.sin_port = htons(src_port);
			sin.sin_addr.s_addr = INADDR_ANY;
			
			//we will try to find a free port down to 512
			while (!bind_ok && src_port >= 512) {
				
				ret = bind(s, (struct sockaddr *) &sin, sizeof(sin));

				if (ret == -1) {
					if (errno == EADDRINUSE) {
						src_port--;
						sin.sin_port = htons(src_port);
					} else {
						perror("internal_hydra_connect error");
						close(s);
						return -1;
					}
				} else
					bind_ok = 1;
			}
		}  //src_port ok
		
		/* memcpy(&target.sin_addr.s_addr, &host[1], 4); */
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
		target.sin_addr.s_addr = inet_addr(host);
		
		signal(SIGALRM, alarming);
		do {
			if (fail > 0)
				sleep(WAIT_BETWEEN_CONNECT_RETRY);
			alarm_went_off = 0;
			alarm(waittime);

			ret = connect(s, (struct sockaddr *) &target, sizeof(target));
			alarm(0);
			if (ret < 0 && alarm_went_off == 0) {
				fail++;
			}
		} while (ret < 0 && fail <= MAX_CONNECT_RETRY && do_retry);
   
		if (ret < 0 && fail > MAX_CONNECT_RETRY) {
			close(s);
			ret = -1;
			return ret;
		}
		
		ret = s;
		return ret;
	}
	
	return ret;
}

int hydra_connect_udp(char *host, int port) {
	return (internal__hydra_connect(host, port, SOCK_DGRAM, 17));
}

int hydra_send(int socket, char *buf, int size) {
	int sendn;
	
	sendn = send(socket, buf, size, 0);
	if(-1 == sendn)
		printf("send failed...\n");
	printf("ok: send size: %d\n", size);
	
	return sendn; 
}

int hydra_recv(int socket, char *buf, int length) {
	int ret;
	
	ret = recv(socket, buf, length, 0);
	return ret;
}

/* handles select errors */
int my_select(int fd, fd_set * fdread, fd_set * fdwrite, fd_set * fdex, long sec, long usec) {
	int ret_val;
	struct timeval stv;
	fd_set *fdr2, *fdw2, *fde2;
	
	do {
		fdr2 = fdread;
		fdw2 = fdwrite;
		fde2 = fdex;
		stv.tv_sec = sec;
		stv.tv_usec = usec;
		ret_val = select(fd, fdr2, fdw2, fde2, &stv);
		/* XXX select() sometimes returns errno=EINTR (signal found) */
	} while (ret_val == -1 && errno == EINTR);
	
	return ret_val;
}

int hydra_data_ready_timed(int socket, long sec, long usec) {
	fd_set fds;
 
	FD_ZERO(&fds);
	FD_SET(socket, &fds);
	return (my_select(socket + 1, &fds, NULL, NULL, sec, usec));
}

int start_snmp(int s, char *ip, int port, int snmpversion) {
	char pass[64], buffer[1024], buf[1024];
	int i, j, size;
	
	memset(pass, 0, sizeof(pass));
	strcpy(pass, "public");
	
	/* do we attack snmp v1 or v2c? */
	if (snmpversion == 2) {
		snmpv1_a.ver[2] = '\x01';
	}
	
	size = sizeof(snmpv1_r);
	
	snmpv1_a.comlen = (char) strlen(pass);
	snmpv1_a.len = snmpv1_a.comlen + size + sizeof(snmpv1_a) - 3;
	
	i = sizeof(snmpv1_a);
	memcpy(buffer, &snmpv1_a, i);
	strcpy(buffer + i, pass);
	i += strlen(pass);
	
	memcpy(buffer + i, &snmpv1_r, size);
	i += sizeof(snmpv1_r);
	
	j = 0;
	do {
		if (hydra_send(s, buffer, i - 1) < 0)
			return 3;
		j++;
	} while (hydra_data_ready_timed(s, 1, 0) <= 0 && j < 3);
	
	if (hydra_data_ready_timed(s, 5, 0) > 0) {
		
		i = hydra_recv(s, (char *) buf, sizeof(buf));
		printf("recv size: %d\n", i);
		
		for (j = 0; j < i; j++) {
			if (buf[j] == '\x04') { /* community name */
				for (j = j + buf[j + 1]; j + 2 < i; j++) {
					if (buf[j] == '\xa2') {     /* PDU Response */
						for (; j + 2 < i; j++) {
							if (buf[j] == '\x02') { /* ID */
								for (j = j + (buf[j + 1]); j + 2 < i; j++) {
									if (buf[j] == '\x02') {
										if (buf[j + 1] == '\x01') {       /* good ! */
											printf("find it~~~~~~~~\n");
											return 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 1;
}

void service_snmp(char *ip, int snmpversion, int port) {
	int run = 1, next_run = 1, sock = -1, i = 0;
	int myport = PORT_SNMP;
	
	snmpversion = 2;
	
	if (port != 0)
		myport = port;
	
	sock = hydra_connect_udp(ip, myport); //sock connect, create socket
	
	port = myport;
	printf("port:%d\n", port);
	start_snmp(sock, ip, port, snmpversion);
	
}

int main(void){
	char *ip = "192.168.1.107";
	int snmpversion = 2;
	int port = 161;
	
	service_snmp(ip, snmpversion, port);
	
	return 1;
}
