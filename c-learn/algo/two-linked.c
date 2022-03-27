#include<stdio.h>
#include<malloc.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
      int val;
      struct ListNode *next;
  };

 struct ListNode* create_node(int val){
    struct ListNode* temp = malloc(sizeof(struct ListNode));

    temp->val = val;
    temp->next = NULL;

    return temp;
 }
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;

    struct ListNode* p = l1;
    int carry = 0;
    int sum;
    while(l1 && l2){
        sum = l1->val + l2->val + carry;
        l1->val = sum % 10;
        carry = sum / 10;

        if(l1->next == NULL)
            break;
        if(l2->next == NULL)
            break;
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l2->next)
        l1->next = l2->next;

    struct ListNode* temp;
    l1 = l1->next;
    while(carry && l1){
        sum = l1->val + carry;
        l1->val = sum % 10;
        carry = sum / 10;

        if(!carry) //可以停止了
            break;

        if(carry && (l1->next == NULL)){
            temp = create_node(carry);
            l1->next = temp;
            break;
        }

        l1 = l1->next;
    }

    return p;
}

int main(void){
    struct ListNode *p1 = create_node(9);
    struct ListNode *p2 = create_node(8);
    p1->next = p2;
    struct ListNode *q1 = create_node(1);
    addTwoNumbers(p1, q1);

    printf("%d ", p1->val);
    printf("%d ", p1->next->val);
    /* printf("%d ", p1->next->next->val); */

    return 0;
}
