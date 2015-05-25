#ifndef MSH_IPROUTETABLE_H
#define MSH_IPROUTETABLE_H


#include "define.h"
#include "topology-discovery.h"

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct msh_ipRouteTable_data_s {
		char        ipRouteDest[IPADDRESS_LEN];
		char        ipRouteNextHop[IPADDRESS_LEN];
		u_long      ipRouteType;
		char        ipRouteMask[IPADDRESS_LEN];
	} msh_route_table;
	
	/* --- variable--- */
	extern msh_route_table RTable[MAX_ROUTE_ENTRY];  //global variable, store all the route table element
	extern msh_route_table *rtablep;
	extern int route_entry_count;  // record the number of the row in the route table 
	extern int rt_idx;  //index with the route table
	/* --- function--- */

	void initialize (void);
	int  print_result (int status, struct snmp_session *sp, struct snmp_pdu *pdu, int pre_index);
	/* msh  amazing!! when the function is print_route_table, gcc will say multi define the function */
	/* so in the library must have a function named print_route_table, so I change it to anther name */
	void print_route_table_entry();
	void synchronous(void);

#ifdef __cplusplus
}
#endif

#endif



