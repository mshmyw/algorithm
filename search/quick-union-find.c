//file name : union-find.c
//created at: Thu Jun 11 11:15:59 2015
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

bool get_memory(int **p_str, int size){
    assert(p_str != NULL && size != 0);

    int **ptr = p_str;
    *ptr = (int *)malloc(sizeof(int) * size);

    return (*ptr != NULL);
}

typedef struct UF{
    int *id;
    int id_length;
    int count;
}UF, *PUF;

void init(PUF puf, int N){
    int i;

    puf->id_length = N;
    puf->count = N;
    if(get_memory(&(puf->id), N))
        for(i = 0; i < N; i++)
            puf->id[i] = i;

    return;
}

int count(PUF puf){
    return puf->count;
}

int find(PUF puf, int p){
    while(p != puf->id[p])
        p = puf->id[p];

    return puf->id[p];
}

bool connected(PUF puf, int p, int q){

    return find(puf, p) == find(puf, q);
}

void quick_union(PUF puf, int p, int q){
   int p_root = find(puf, p);
    int q_root = find(puf, q);

    if(p_root == q_root) return;

    puf->id[p_root] = q_root;
    puf->count--;

    return;
}

void print(int *a, int N){
    int i;
    for (i = 0; i < N; i++)
        printf("%2d", a[i]);
    printf("\n");

    return;
}

#define MAX 100

int main(void){
    FILE *fp;
    fp = fopen("union-input", "r");
    char buf[MAX];
    int p = 0, q = 0;
    UF uf;
    PUF puf = &uf;
    init(puf, 10);

    while(!feof(fp)){
        memset(buf, 0, sizeof(buf));
        fgets(buf, MAX, fp);
        sscanf(buf, "%d %d", &p, &q);
        if(connected(puf, p, q))continue;
        quick_union(puf, p, q);
        printf("%d<-->%d \n", p, q);
        print(puf->id, 10);
    }
    print(puf->id, 10);
    printf("count->%d \n", puf->count);
    return 0;
}
