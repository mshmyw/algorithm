//file name : robot.c
//created at: Sun Aug 30 15:06:41 2015
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

/*
时间限制：1秒空间限制：32768K
通过比例：21.38%
最佳记录：0 ms|8552K （来自  zql）
题目描述

地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 */

#define M 256
#define N 256
bool visited[M][N];
int sum = 0;
int count = 0;

int pos_sum(int rows, int cols){
    int row, col, tmp_sum = 0;
    for(row = rows; row != 0; row = row / 10)
        tmp_sum += row % 10;

    for(col = cols; col != 0; col = col / 10)
        tmp_sum += col % 10;
    sum = tmp_sum;

    return sum;
}

void moving_count_consider_child_dfs(int threshold, int i, int j, int row, int col){
    if(i < 0 || j < 0 || i >= row || j >= col || visited[i][j])
        return;

    visited[i][j] = true;
    if(pos_sum(i, j) != threshold)
        return;

    count++;
    moving_count_consider_child_dfs(threshold, i - 1, j, row, col); //up
    moving_count_consider_child_dfs(threshold, i, j - 1, row, col); //left
    moving_count_consider_child_dfs(threshold, i + 1, j, row, col); //down
    moving_count_consider_child_dfs(threshold, i, j + 1, row, col); //right

    /* if((i - 1 >= 0) && visited[i - 1][j] == 0){ */
    /*         visited[i - 1][j] = 1; */
    /*         printf(" -(%d %d)- \n", i - 1, j); */
    /*         moving_count(threshold, i - 1, j, row, col); //up */
    /* } */

    /* if((j - 1 >= 0) && visited[i][j - 1] == 0){ */
    /*     visited[i][j - 1] = 1; */
    /*             printf(" -(%d %d)- \n", i, j - 1); */
    /*     moving_count(threshold, i, j - 1, row, col); //left */
    /* } */

    /* if((j + 1 < col) && visited[i][j + 1] == 0){ */
    /*     visited[i][j + 1] = 1; */
    /*     printf(" -(%d %d)- \n", i, j + 1); */
    /*     moving_count(threshold, i, j + 1, row, col); //right */
    /* } */

    /* if((i + 1 < row ) && visited[i + 1][j] == 0){ */
    /*     visited[i + 1][j] = 1; */
    /*     printf(" -(%d %d)- \n", i + 1, j); */
    /*     moving_count(threshold, i + 1, j, row, col); //down */
    /* } */

    return;
}

void moving_count(int threshold, int i, int j, int row, int col){
    if(i < 0 || j < 0 || i >= row || j >= col || visited[i][j])
        return;
    if(pos_sum(i, j) > threshold)
        return;

    visited[i][j] = true;
    count++;
    moving_count(threshold, i - 1, j, row, col); //up
    moving_count(threshold, i, j - 1, row, col); //left
    moving_count(threshold, i + 1, j, row, col); //down
    moving_count(threshold, i, j + 1, row, col); //right
    return;
}

int movingCount(int threshold, int rows, int cols){
    if(threshold < 0)
        return 0;
    memset(visited, 0, sizeof(visited));
    moving_count(threshold, 0, 0, rows, cols);

    int k;
    for(k = 0; k < rows; k++)
        print(visited[k], cols);
    return count;
}

int main(void){
    int sum = 0;
    int threshold = 5;
    movingCount(threshold, 10, 10);

    printf("COUNT %d\n", count);
    return 0;
}
