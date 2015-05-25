#include "./include/net-snmp/net-snmp-config.h"
#include "./include/net-snmp/net-snmp-includes.h"

#include "topology-queue.h"
#include <assert.h>

/*------------------------------------------------------------
操作目的：   初始化队列
初始条件：   无
操作结果：   构造一个空的队列
函数参数：
        LinkQueue *Q    待初始化的队列
返回值：
        int            操作是否成功
------------------------------------------------------------*/
int InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (Pnode)malloc(sizeof(Node));
    if(Q->front == NULL)
        return 0;
    Q->front->next = NULL;
    return 1;
}
 
/*-p-----------------------------------------------------------
操作目的：   销毁队列
初始条件：   队列Q已存在
操作结果：   销毁队列Q
函数参数：
        LinkQueue *Q    待销毁的队列
返回值：
        无
------------------------------------------------------------*/
void DestroyQueue(LinkQueue *Q)
{
    assert(Q != NULL);
    while(Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}
 
/*------------------------------------------------------------
操作目的：   判断队列是否为空
初始条件：   队列Q已存在
操作结果：   若Q为空队列，则返回true，否则返回false
函数参数：
        LinkQueue Q     待判断的队列
返回值：
        int            是否为空
------------------------------------------------------------*/

int QueueEmpty(LinkQueue Q)
{
    assert(Q.front != NULL && Q.rear != NULL);
    if(Q.front == Q.rear)
        return 1;
    else
        return 0;
}
/*------------------------------------------------------------
操作目的：   得到队列的长度
初始条件：   队列Q已存在
操作结果：   返回Q中数据元素的个数
函数参数：
        LinkQueue Q     队列Q
返回值：
        int             数据元素的个数
------------------------------------------------------------*/
int QueueLength(LinkQueue Q)
{
    assert(Q.front != NULL);
    Pnode p = Q.front;
    int Length = 0;
    while (p != Q.rear)
    {
        Length++;
        p = p->next;
    }
    return Length;
}
/*------------------------------------------------------------
操作目的：   得到队列首元素
初始条件：   队列Q已存在
操作结果：   用e返回队列首元素
函数参数：
        LinkQueue Q     队列Q
        ElemType *e     队列首元素的值
返回值：
        int            操作是否成功
------------------------------------------------------------*/
int GetHead(LinkQueue Q, ElemType *e)
{
    assert(Q.front != NULL);
    if(QueueEmpty(Q))
        return 0;
    else
    {
        strncpy(e, Q.front->next->IpAddr, Q.front->next->IpAddrLen);
        return 1;
    }
     
}
/*------------------------------------------------------------
操作目的：   遍历队列
初始条件：   队列Q已存在
操作结果：   依次对Q的每个元素调用函数fp
函数参数：
        LinkQueue Q     队列Q
        void (*fp)()    访问每个数据元素的函数指针
返回值：
        无
------------------------------------------------------------*/
void QueueTraverse(LinkQueue Q)
{
    assert(Q.front != NULL);
    Pnode p = Q.front->next;
    while(p)
    {
		printf("%s ", p->IpAddr);
        p = p->next;
    }
}
 
/*------------------------------------------------------------
操作目的：   在队列末尾插入元素e
初始条件：   队列Q已存在
操作结果：   插入元素e作为队列新的尾结点
函数参数：
        LinkQueue *Q        队列Q
        ElemType e      待插入的数据元素
返回值：
        int            操作是否成功
------------------------------------------------------------*/
int EnQueue(LinkQueue *Q, ElemType *e, int e_len)
{
    Pnode temp = (Pnode)malloc(sizeof(Node));
    if(!temp)
        return 0;
	memset(temp->IpAddr, 0, sizeof(temp->IpAddr));  //must reset ipaddr, before use
	strncpy(temp->IpAddr, e, e_len);
	temp->IpAddrLen = e_len;
    temp->next = NULL;
    Q->rear->next = temp;
    Q->rear = temp;
    return 1;
}
 
/*------------------------------------------------------------
操作目的：   删除链式队列的头结点
初始条件：   队列Q已存在
操作结果：   删除链式队列的头结点
函数参数：
        LinkQueue *Q        队列Q
        ElemType *e     待插入的数据元素
返回值：
        int            操作是否成功
------------------------------------------------------------*/
int DeQueue(LinkQueue *Q, ElemType *e)
{
    if(Q->front == Q->rear)
        return 0;
  Pnode temp = Q->front->next;
  strncpy(e, temp->IpAddr, temp->IpAddrLen);
  Q->front->next= temp->next;
    if(Q->rear == temp)
        Q->rear = Q->front;
    free(temp);
    return 1;
}


/* queue for subnet or connect */

/*------------------------------------------------------------
  操作目的：   初始化队列
  初始条件：   无
  操作结果：   构造一个空的队列
  函数参数：
  LinkQueue2 *Q    待初始化的队列
  返回值：
  int            操作是否成功
  ------------------------------------------------------------*/
int InitQueue2(LinkQueue2 *Q)
{
    Q->front = Q->rear = (Pnode2)malloc(sizeof(Node2));
    if(Q->front == NULL)
        return 0;
    Q->front->next = NULL;
    return 1;
}
 
/*-p-----------------------------------------------------------
  操作目的：   销毁队列
  初始条件：   队列Q已存在
  操作结果：   销毁队列Q
  函数参数：
  LinkQueue2 *Q    待销毁的队列
  返回值：
  无
  ------------------------------------------------------------*/
void DestroyQueue2(LinkQueue2 *Q)
{
    assert(Q != NULL);
    while(Q->front)
		{
			Q->rear = Q->front->next;
			free(Q->front);
			Q->front = Q->rear;
		}
}
 
/*------------------------------------------------------------
  操作目的：   判断队列是否为空
  初始条件：   队列Q已存在
  操作结果：   若Q为空队列，则返回true，否则返回false
  函数参数：
  LinkQueue2 Q     待判断的队列
  返回值：
  int            是否为空
  ------------------------------------------------------------*/

int QueueEmpty2(LinkQueue2 Q)
{
    assert(Q.front != NULL && Q.rear != NULL);
    if(Q.front == Q.rear)
        return 1;
    else
        return 0;
}
/*------------------------------------------------------------
  操作目的：   得到队列的长度
  初始条件：   队列Q已存在
  操作结果：   返回Q中数据元素的个数
  函数参数：
  LinkQueue2 Q     队列Q
  返回值：
  int             数据元素的个数
  ------------------------------------------------------------*/
int QueueLength2(LinkQueue2 Q)
{
    assert(Q.front != NULL);
    Pnode2 p = Q.front;
    int Length = 0;
    while (p != Q.rear)
		{
			Length++;
			p = p->next;
		}
    return Length;
}
/*------------------------------------------------------------
  操作目的：   得到队列首元素
  初始条件：   队列Q已存在
  操作结果：   用e返回队列首元素
  函数参数：
  LinkQueue2 Q     队列Q
  ElemType *e     队列首元素的值
  返回值：
  int            操作是否成功
  ------------------------------------------------------------*/
int GetHead2(LinkQueue2 Q, ElemType *suborfrom, ElemType *maskorto)
{
    assert(Q.front != NULL);
    if(QueueEmpty2(Q))
        return 0;
    else
		{
			strncpy(suborfrom, Q.front->next->IpAddr1, Q.front->next->IpAddr1Len);
			strncpy(maskorto, Q.front->next->IpAddr2, Q.front->next->IpAddr2Len);
			return 1;
		}
}
/*------------------------------------------------------------
  操作目的：   遍历队列
  初始条件：   队列Q已存在
  操作结果：   依次对Q的每个元素调用函数fp
  函数参数：
  LinkQueue2 Q     队列Q
  void (*fp)()    访问每个数据元素的函数指针
  返回值：
  无
  ------------------------------------------------------------*/
void QueueTraverse2(LinkQueue2 Q)
{
    assert(Q.front != NULL);
    Pnode2 p = Q.front->next;
    while(p)
		{
			printf("<%s %s> ", p->IpAddr1, p->IpAddr2);
			p = p->next;
		}
}
 
/*------------------------------------------------------------
  操作目的：   在队列末尾插入元素e
  初始条件：   队列Q已存在
  操作结果：   插入元素e作为队列新的尾结点
  函数参数：
  LinkQueue2 *Q        队列Q
  ElemType e      待插入的数据元素
  返回值：
  int            操作是否成功
  ------------------------------------------------------------*/
int EnQueue2(LinkQueue2 *Q, ElemType *suborfrom, int suborfrom_len, ElemType *maskorto, int maskorto_len)
{
    Pnode2 temp = (Pnode2)malloc(sizeof(Node2));
    if(!temp)
        return 0;
	memset(temp->IpAddr1, 0, sizeof(temp->IpAddr1));  //must reset ipaddr, before use
	strncpy(temp->IpAddr1, suborfrom, suborfrom_len);
	temp->IpAddr1Len = suborfrom_len;
	memset(temp->IpAddr2, 0, sizeof(temp->IpAddr2));  //must reset ipaddr, before use
	strncpy(temp->IpAddr2, maskorto, maskorto_len);
	temp->IpAddr2Len = maskorto_len;
    temp->next = NULL;
    Q->rear->next = temp;
    Q->rear = temp;
    return 1;
}
 
/*------------------------------------------------------------
  操作目的：   删除链式队列的头结点
  初始条件：   队列Q已存在
  操作结果：   删除链式队列的头结点
  函数参数：
  LinkQueue2 *Q        队列Q
  ElemType *e     待插入的数据元素
  返回值：
  int            操作是否成功
  ------------------------------------------------------------*/
int DeQueue2(LinkQueue2 *Q, ElemType *suborfrom, ElemType *maskorto)
{
    if(Q->front == Q->rear)
        return 0;
	Pnode2 temp = Q->front->next;
	strncpy(suborfrom, temp->IpAddr1, temp->IpAddr1Len);
	strncpy(maskorto, temp->IpAddr2, temp->IpAddr2Len);
	Q->front->next= temp->next;
    if(Q->rear == temp)
        Q->rear = Q->front;
    free(temp);
    return 1;
}
