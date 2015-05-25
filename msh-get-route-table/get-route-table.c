#include "./include/net-snmp/net-snmp-config.h"
#include "./include/net-snmp/net-snmp-includes.h"

#include "msh_ipRouteTable.h"

#ifdef HAVE_WINSOCK_H
#include <winsock.h>
#endif

int main (int argc, char **argv)
{
	rtablep = RTable;  // route table pointer, point the route table
	rt_idx = 0;  //route table index glable variable
	route_entry_count = 0;  // table entry total number
	
	initialize();
	printf("------ Kernel IP routing table ------\n");
	synchronous();
	queue_test();
	
	return 0;
}

