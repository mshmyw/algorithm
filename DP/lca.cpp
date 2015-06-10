//file name : lca.cpp
//created at: Wed Jun 10 10:20:40 2015
//author:     msh

// 二叉树LCA在线算法, 转化为RMQ问题

#include <iostream>
#include <stdio.h>
#include <cmath>

#define MAX 10

using namespace std;

int dfs[2*MAX];
int depth[2*MAX];
int pos[MAX];  // first apparence position
int M[2*MAX][2*MAX];
int len=0;  // denote the subscript of the array

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int val, Node *l, Node *r)
    {
        value=val;
        left=l;
        right=r;
    }
};

// Depth First Search
int DFS(Node *root, int d)
{
    if(root == NULL)
        return 0;

    dfs[len]=root->value;
    depth[len]=d;
    pos[root->value - 1]=len;  //
    len++;

    DFS(root->left, d+1);
    // left backtrack
    if(root->left!=NULL)
        {
            dfs[len]=root->value;
            depth[len]=d;
            len++;
        }

    DFS(root->right, d+1);
    // right backtrack
    if(root->right!=NULL)
        {
            dfs[len]=root->value;
            depth[len]=d;
            len++;
        }

    return 0;
}

//
int RMQ()
{
    int i, j;
    int lenJ=(int)sqrt(len);


    for(i=0;i<len;i++)
        M[i][0]=i;
    for(j=1;j<=lenJ;j++)
        {
            for(i=0;i+(1<<j)-1<len;i++)
                M[i][j]=(depth[M[i][j-1]]<depth[M[i+(1<<(j-1))][j-1]])?(M[i][j-1]):(M[i+(1<<(j-1))][j-1]);
        }

    return 0;
}

int Query(Node *a, Node *b)
{
    int i=pos[a->value-1], j=pos[b->value-1];
    int temp;
    if(i>j)
        {
            temp=j;
            i=j;
            j=temp;
        }
    int k=(int)sqrt(j-i+1);

    // pay attention to the relation
    int minpos=(depth[M[i][k]]<depth[M[j+1-(1<<k)][k]])?(M[i][k]):(M[j+1-(1<<k)][k]);
    int nodeval=dfs[minpos];

    printf("The LCA of node %d and node %d is node %d\n", a->value, b->value, nodeval);

    return 0;
}

int main()
{
    Node *n3 = new Node(3, NULL, NULL);
    Node *n5 = new Node(5, NULL, NULL);
    Node *n6 = new Node(6, NULL, NULL);
    Node *n8 = new Node(8, NULL, NULL);
    Node *n4 = new Node(4, n5, n6);
    Node *n7 = new Node(7, NULL, n8);
    Node *n2 = new Node(2, n3, n4);
    Node *n1 = new Node(1, n2, n7);

    DFS(n1, 0); // pass parameter depth
    RMQ();
    Query(n4, n8);

    return 0;
}
