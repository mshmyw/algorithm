#ifndef TOPOLOGY_QUEUE_H
#define TOPOLOGY_QUEUE_H

#include "define.h"

#ifdef __cplusplus
extern "C" {
#endif

	/*------------------------------------------------------------
// 链式队列结构的定义
------------------------------------------------------------*/
	typedef char ElemType;
	
	typedef struct Node
	{
		ElemType IpAddr[IPADDRESS_LEN];              // 元素数据
		int      IpAddrLen;
		struct Node *next;          // 链式队列中结点元素的指针
	} Node, *Pnode;
	typedef struct LinkQueue
	{
		Pnode front;             // 队列头指针
		Pnode rear;              // 队列尾指针
	}LinkQueue;
	
	/*------------------------------------------------------------
// 链式队列的基本操作
------------------------------------------------------------*/
	
	int InitQueue(LinkQueue *Q);
	void DestroyQueue(LinkQueue *Q);
	int QueueEmpty(LinkQueue Q);
	int  QueueLength(LinkQueue Q);
	int GetHead(LinkQueue Q, ElemType *e);
	void QueueTraverse(LinkQueue Q);
	int EnQueue(LinkQueue *Q, ElemType *e, int e_len);
	int DeQueue(LinkQueue *Q, ElemType *e);


	/* sub net and connect */
	typedef struct Node2
{
    ElemType IpAddr1[IPADDRESS_LEN];              // 元素数据
    int      IpAddr1Len;                          //sub net or connect from address
	ElemType IpAddr2[IPADDRESS_LEN];              // 元素数据
    int      IpAddr2Len;                          //subnet mask or to address
	struct Node2 *next;          // 链式队列中结点元素的指针
	} Node2, *Pnode2;
typedef struct LinkQueue2
{
    Pnode2 front;             // 队列头指针
    Pnode2 rear;              // 队列尾指针
}LinkQueue2;

/*------------------------------------------------------------
// 链式队列的基本操作
------------------------------------------------------------*/

	int InitQueue2(LinkQueue2 *Q);
	void DestroyQueue2(LinkQueue2 *Q);
	int QueueEmpty2(LinkQueue2 Q);
	int  QueueLength2(LinkQueue2 Q);
	int GetHead2(LinkQueue2 Q, ElemType *suborfrom, ElemType *maskorto);
	void QueueTraverse2(LinkQueue2 Q);
	int EnQueue2(LinkQueue2 *Q, ElemType *suborfrom, int suborfrom_len, ElemType *maskorto, int maskorto_len);
	int DeQueue2(LinkQueue2 *Q, ElemType *suborfrom, ElemType *maskorto);

#ifdef __cplusplus
}
#endif

#endif

