//file name : max-sum.c
//created at: Tue Aug 11 11:25:35 2015
//author:  root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

typedef struct _AB{
    unsigned short int ab;
    unsigned int bc;
    long long cd;
}AB;

typedef struct node1
    {
        short b;
        int c;
        char a;
        double d;
    } cc1;

typedef struct node2
    {
       int b[2];
       char a;
    } cc2;

typedef struct node3
    {
        short b;
        char c[5];
        char a;
        double d;
    } cc3;

typedef struct node4
{
   double dda;
   char cda;
   int ida;
}cc4;

typedef struct node5
{
    char cda;
    double dda;
    int ida;
}cc5;

typedef struct node
{
    int a;//4
    int (*fun)(void);
}Node;

int test()
{
    printf("hello world\n");
    return 1;
}

int main(void){
    int a[5] = {1, 3, 2, 4, 5};
    int *ptr = (int *)(&a + 1);
    printf("%d %d\n", *(a + 1), *(ptr - 1));
    printf("SIZE %d", sizeof(AB));

    printf("--%d %d %d %d %d--\n", sizeof(cc1), sizeof(cc2), sizeof(cc3), sizeof(cc4), sizeof(cc5));

   Node node_a;
    node_a.fun=test;
    printf("sizeof Node is %d\n",sizeof(node_a));//16
    (*node_a.fun)();

    return 0;
}
