//file name : rebuild-tree.c
//created at: Thu Aug 20 10:08:53 2015
//author:  root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0

int max(int a, int b){
    if(a > b)
        return a;

    return b;
}

int min(int a, int b){
    if(a < b)
        return a;

    return b;
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;

    return;
}

void print(int *a, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%3d", a[i]);

    printf("\n");

    return;
}

typedef int ITYPE;
typedef struct _NODE{
    struct _NODE *lchd;
    struct _NODE *rchd;
    ITYPE value;
}NODE;

typedef NODE *PNODE;

#define DEBUGED 0
int debug_count = 0;
void debug_print(ITYPE value){
if(DEBUGED)
    printf("debug-count-%d-%d-\n", debug_count++, value);
    return;
}

PNODE rebuild_tree_inner(ITYPE *pleft, ITYPE *pright, ITYPE *ileft, ITYPE *iright){
    if(ileft > iright)
        return NULL;
    PNODE root = (PNODE)malloc(sizeof(NODE));
    root->value = *pleft;

    ITYPE *dym_ptr = ileft;
    while(*dym_ptr != *pleft)dym_ptr++;
    debug_print(*dym_ptr);
    root->lchd = rebuild_tree_inner(pleft + 1, pleft + (dym_ptr - ileft), ileft, dym_ptr - 1);
    root->rchd = rebuild_tree_inner(pleft + (dym_ptr - ileft + 1), pright, dym_ptr + 1, iright);
    return root;
}

PNODE rebuild_tree(ITYPE *preorder, ITYPE *inorder, int len){
    assert(preorder && inorder && len > 0);
    return rebuild_tree_inner(preorder, preorder + len - 1, inorder, inorder + len - 1);
}

void print_tree(PNODE root){
    if(root == NULL)
        return;

    printf("%d ", root->value);
    print_tree(root->lchd);
    print_tree(root->rchd);
}

#define N 64
int res[N];
//similar space answer tree
void bin_tree_path_sum_inner(PNODE root, int i, int sum){ //similar space answer tree
    if(root == NULL)
        return;
    if(root->lchd == NULL && root->rchd == NULL){
        res[i] = root->value;
        if(sum - res[i] == 0)
            print(res, i + 1);

        return;
    }

    res[i] = root->value; //i just relate with tree high
    bin_tree_path_sum_inner(root->lchd, i + 1, sum - root->value);
    bin_tree_path_sum_inner(root->rchd, i + 1, sum - root->value);
}

void bin_tree_path_sum(PNODE root, int sum){

    memset(res, 0, sizeof(res));
    bin_tree_path_sum_inner(root, 0, sum);
    return;
}
int main(void){

    int preorder[] = {1, 2, 4, 7, 3, 10, 6, 8};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    int inorder[] = {4, 7, 2, 1, 10, 3, 8, 6};

    PNODE root = rebuild_tree(preorder, inorder, n);
    print_tree(root);
    printf("\n");
    int sum = 14;
    bin_tree_path_sum(root, sum);

    return 0;
}
