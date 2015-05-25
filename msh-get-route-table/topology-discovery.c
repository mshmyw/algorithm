#include "./include/net-snmp/net-snmp-config.h"
#include "./include/net-snmp/net-snmp-includes.h"

#include "topology-discovery.h"
#include "topology-queue.h"

/* topology discovery queue */
LinkQueue    *pwaitRtrQueue, *pdiscoveredRtrQueue;       // wait and dectect route queue
LinkQueue	 *psubnetQueue, *pconnect_queue;             //sub net and connect queue;

void queue_test()
{
    LinkQueue W;
	char e[16] = "ab";
    InitQueue(&W);
	EnQueue(&W, e, strlen(e));
	char *pelement, element[512];
	memset(element, 0, sizeof(element));    //this is must do.
	pelement = element;
	GetHead(W, pelement);
	printf("--queue element-- %s\n", pelement);
	DestroyQueue(&W);
	return;
}

/* void topology_discovery(){ */
/* 	Gate g ＝ GetDefaultGate()；//得到默认网关 */
/* 		if (g 确实是路由设备) */
/* 			printf("g is gateway...\n'");//TODO 把该设备添加到 RouteList 链表的末尾 */
/* 			return; */
/* } */
/* Gate g ＝ GetDefaultGate ()；//得到默认网关 */
/* 	if (g 确实是路由设备) */
/* 		//TODO 把该设备添加到 RouteList 链表的末尾 */
		
/* 		for（RouteList 中的每一个路由器 CurrentRouter） */
/* 		//遍历该路由器的路由表，提取路由器和子网信息 */
/* { */
/* 	for (CurrentRouter 的路由表的每一项) */
/* 		{ */
/* 			if (ipRouteType 为 direct) */
/* 				{ */
/* 					if ( ipRouteMask 为 255.255.255.255) */
/* 						{ */
/* 							if (ipRouteNextHop 所代表的路由器不在 RouteList 中) */
/* 								{ */
/* 									把 IpRouteNextHop 所代表的路由器添加到 RouteList 尾部； */
/* 										把当前路由器CurrentRouter和IpRouteNextHop代表的路由器之 */
/* 										间的链接添加到链表 LinkList 中； */
/* 										} */
/* 						} */
/* 					else */
/* 						{ */
/* 							把 ipRouteDest 和 ipRouteMask 所代表的子网添加到 SubnetList 中去； */
/* 								把该子网与当前路由器 CurrentRouter 之间的连接添加到 LinkList 中； */
/* 								} */
/* 				} */
/* 			if (ipRouteType 为 indirect) */
/* 				{ */
/* 					if (ipRouteNextHop 所代表的路由器不在 RouteList 中) */
/* 						{ */
/* 							把 IpRouteNextHop 所代表的路由器添加到 RouteList 尾部； */
/* 								把当前路由器 CurrentRouter 和 ipRouteNextHop 代表的路由器之 */
/* 								间的链接添加到链表 LinkList 中； */
/* 								} */
/* 				} */
/* 		} */
/* } */
