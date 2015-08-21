//file name : young-table.c
//created at: Fri Jun 12 13:24:32 2015
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
void search_young_table(int *y_tbl, int m, int n, int i, int j, int item){
    if(i >= m || j < 0){
        printf("search %d failed\n", item);
        return;
    }

    if(item < y_tbl[i * n + j])
        search_young_table(y_tbl, m, n, i, j - 1, item);
    else if(item > y_tbl[i * n + j])
        search_young_table(y_tbl, m, n, i + 1, j, item);
    else
        printf("--%d--%d--%d--\n", i, j, y_tbl[i * n + j]);

    return;
}

void search_young_table_iter(int *y_tbl, int m, int n, int item){
    int i, j;

    for(i = 0, j = n - 1; (i < m) && (j >= 0); )

        if(item < y_tbl[i * n + j])
            j--;
        else if(item > y_tbl[i * n + j])
            i++;
        else{
            printf("--%d--%d--%d--\n", i, j, y_tbl[i * n + j]);
            return;
        }

    printf("search %d failed\n", item);
    return;
}

/* the complexity the algorithm is O() */
void search(int *y_tbl, int m, int n, int item){

    search_young_table(y_tbl, m, n, 0, n - 1, item);
    search_young_table_iter(y_tbl, m, n, item);

   return;
}

int main(void){
    int y_tbl[] = {1, 2, 8, 9,
                   2, 4, 9, 12,
                   4, 7, 10, 13,
                   6, 8, 11, 15};

    int m, n;
    m = n = 4;
    int item[] = {1, 4, 12, 8, 15, -1, 19};
    int item_count = sizeof(item) / sizeof(item[0]);

    int i;
    for (i = 0; i < item_count; i++)
        search(y_tbl, m, n, item[i]);

    return 0;
}
