//file name : matrix-clockwise.c
//created at: Thu Jul  9 14:40:08 2015
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

#define N 5
/* int a[N][N] = { */
/*     {1, 2, 3, 4}, */
/*     {5, 6, 7, 8}, */
/*     {9, 10, 11, 12}, */
/*     {13, 14, 15, 16} */
/* }; */

int a[N - 1][N] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20}
    /* {21, 22, 23, 24, 25} */
};

void matrix_clockwise(int r_left, int r_right, int c_left, int c_right){
 ll   if(r_left > r_right || c_left > c_right)
        return;

    int i, j;
    for(i = r_left, j = c_left; j <= c_right; j++)  //-->right
        printf("%3d", a[i][j]);
    for(i++, j--; i <= r_right; i++)  //down
        printf("%3d", a[i][j]);
    for(j--, i--; j >= c_left; j--)  //<--left
        printf("%3d", a[i][j]);
    for(i--, j++; i > r_left; i--)  //-->up
        printf("%3d", a[i][j]);

    matrix_clockwise(r_left + 1, r_right - 1, c_left + 1, c_right - 1);
    return;
}

void matrix(int m, int n){

    matrix_clockwise(0, m - 1, 0, n - 1);
    printf("\n");

    return;
}

int main(void){

    matrix(N - 1, N);

    return 0;
}
