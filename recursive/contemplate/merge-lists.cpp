//file name : merge-list.cpp
//created at: Tue Jul  7 16:46:03 2015
//author:  root

#include <iostream>
using namespace std;


struct LIST_NODE
{
	int         m_Data;
	LIST_NODE*   m_pNext;
	LIST_NODE(int value,LIST_NODE* next = NULL):m_Data(value),m_pNext(next){
        
    }
};

// recursive has great power
//note: for list, you just need know the head of it, then, you will know all about it,
// so, all you should do is get the head of it
LIST_NODE* merge_lists(LIST_NODE* head1,LIST_NODE* head2){
	if (head1 == NULL)
        return head2;
	if(head2 == NULL)
        return head1;

	LIST_NODE* merge_head = NULL;
    if (head1->m_Data < head2->m_Data){
        merge_head = head1;
        merge_head->m_pNext = merge_lists(head1->m_pNext, head2);
    }
	else{
        merge_head = head2;
        merge_head->m_pNext = merge_lists(head1, head2->m_pNext);
    }

    return merge_head;
}

int main(){
    LIST_NODE* pHead1 = new LIST_NODE(1);
    LIST_NODE* pCur = pHead1;
    for (int i = 3; i < 10; i+=2){
        LIST_NODE* tmpNode = new LIST_NODE(i);
        pCur->m_pNext = tmpNode;
        pCur = tmpNode;
    }

    LIST_NODE* pHead2 = new LIST_NODE(2);
    pCur = pHead2;
    for (int j = 4; j < 10; j+=2){
        LIST_NODE* tmpNode = new LIST_NODE(j);
        pCur->m_pNext = tmpNode;
        pCur = tmpNode;
    }

    LIST_NODE* head = merge_lists(pHead1,pHead2);
    while (head){
        cout<<head->m_Data<<" ";
        head=head->m_pNext;
    }
    cout<<endl;
    return 0;
}
