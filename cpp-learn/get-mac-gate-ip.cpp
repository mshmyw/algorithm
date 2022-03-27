#include <stdio.h>
#include <WinSock2.h>
#include <Windows.h>
#include <Iphlpapi.h>
#include <Assert.h>

#pragma warning(disable:4996)

// Link with Iphlpapi.lib
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "ws2_32.lib")

int get_local_mac_ip_and_gw_ip(u_char src_mac_addr[], char src_ip_addr[], char gw_ip_addr[]);
static void print_mac_addr(unsigned char MACData[]);
int get_gw_mac(u_char gw_mac_addr[], char src_ip_addr[], char gw_ip_addr[]){

	DWORD dwRetVal;
	IPAddr DestIp = 0;
	IPAddr SrcIp = 0;       /* default for src ip */
	ULONG MacAddr[2];       /* for 6-byte hardware addresses */
	ULONG PhyAddrLen = 6;  /* default to length of six bytes */

	SrcIp = inet_addr(src_ip_addr);
	DestIp = inet_addr(gw_ip_addr);

	memset(&MacAddr, 0xff, sizeof (MacAddr));

	printf("Sending ARP request for IP address: %s\n", gw_ip_addr);

	dwRetVal = SendARP(DestIp, SrcIp, &MacAddr, &PhyAddrLen);

	if (dwRetVal == NO_ERROR) {
		//Prepare the mac address
		if (PhyAddrLen){
			BYTE *bMacAddr = (BYTE *)& MacAddr;
			for (int i = 0; i < (int)PhyAddrLen; i++)
				gw_mac_addr[i] = (char)bMacAddr[i];

			return true;
		}
	
	}
	else {
		printf("Error: SendArp failed with error: %d", dwRetVal);
		switch (dwRetVal) {
		case ERROR_GEN_FAILURE:
			printf(" (ERROR_GEN_FAILURE)\n");
			break;
		case ERROR_INVALID_PARAMETER:
			printf(" (ERROR_INVALID_PARAMETER)\n");
			break;
		case ERROR_INVALID_USER_BUFFER:
			printf(" (ERROR_INVALID_USER_BUFFER)\n");
			break;
		case ERROR_BAD_NET_NAME:
			printf(" (ERROR_GEN_FAILURE)\n");
			break;
		case ERROR_BUFFER_OVERFLOW:
			printf(" (ERROR_BUFFER_OVERFLOW)\n");
			break;
		case ERROR_NOT_FOUND:
			printf(" (ERROR_NOT_FOUND)\n");
			break;
		default:
			printf("\n");
			break;
		}
	}

	return false;
}
int main(){
	u_char src_mac_addr[6], gw_mac_addr[6];
	char src_ip_addr[16], gw_ip_addr[16];
	get_local_mac_ip_and_gw_ip(src_mac_addr, src_ip_addr, gw_ip_addr);
	print_mac_addr(src_mac_addr);
	get_gw_mac(gw_mac_addr, src_ip_addr, gw_ip_addr);
	print_mac_addr(gw_mac_addr);

	printf("src ip:%s--\n", src_ip_addr);
	printf("ip:%s--\n", gw_ip_addr);
	system("pause");
}

// Prints the MAC address stored in a 6 byte array to stdout
static void print_mac_addr(unsigned char MACData[])
{
	printf("MAC Address: %02X-%02X-%02X-%02X-%02X-%02X\n",
		MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);
}

int get_local_mac_ip_and_gw_ip(u_char src_mac_addr[], char src_ip_addr[], char gw_ip_addr[]){
	PIP_ADAPTER_INFO AdapterInfo;
	DWORD dwBufLen = sizeof(AdapterInfo);
	//u_char mac_addr[6];

	AdapterInfo = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
	if (AdapterInfo == NULL) {
		printf("Error allocating memory needed to call GetAdaptersinfo\n");
		return false;
	}

	// Make an initial call to GetAdaptersInfo to get the necessary size into the dwBufLen     variable
	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == ERROR_BUFFER_OVERFLOW) {

		AdapterInfo = (IP_ADAPTER_INFO *)malloc(dwBufLen);
		if (AdapterInfo == NULL) {
			printf("Error allocating memory needed to call GetAdaptersinfo\n");
			return false;
		}
	}

	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR) {
		PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
		do {
			switch (pAdapterInfo->Type){
			case MIB_IF_TYPE_ETHERNET:
				if (strstr(pAdapterInfo->Description, "VMnet") == NULL){

					for (int i = 0; i < pAdapterInfo->AddressLength; i++)
						src_mac_addr[i] = pAdapterInfo->Address[i];

					printf("Local Address: %s\n", pAdapterInfo->IpAddressList.IpAddress.String);
					printf("Gateway:       %s\n", pAdapterInfo->GatewayList.IpAddress.String);
					strcpy_s(src_ip_addr, 16, pAdapterInfo->IpAddressList.IpAddress.String);
					strcpy_s(gw_ip_addr, 16, pAdapterInfo->GatewayList.IpAddress.String);

				}
				break;
			default:
				break;
			}
			pAdapterInfo = pAdapterInfo->Next;
		} while (pAdapterInfo);
	}
	free(AdapterInfo);

	return true;
}
