// Program to find best buying and selling days
#include <stdio.h>

void print(int a[], int n){
	int i;
	
	for(i = 0; i < n; i++)
		printf(" %d", a[i]);
	printf("\n");

	return;
}

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	struct ListNode *p, *q;
	
	if(NULL == head)
		return false;
	if(NULL == head->next)
		return false;

	p = head->next;
	if(NULL == p->next)
		return false;
	
	q = p->next;
	
	while(NULL != q){
		if(q == q)
			return true;
		p = p->next;
		q = q->next->next;
	}
	
	return false;
}
 
// Driver program to test above functions
int main()
{
  // stock prices on consecutive days
  int price[] = {800, 180, 260, 310, 40, 535, 695, 220};
  int n = sizeof(price)/sizeof(price[0]);  //dynamic get it;
  
  // fucntion call
  max_profit(price, n);
  return 0;
}

