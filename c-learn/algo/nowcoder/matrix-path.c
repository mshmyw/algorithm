//file name : matrix-path.c
//created at: Mon Aug 31 08:40:06 2015
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
  请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bccced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
 */
#define N 1024
int visited[N];
int subvisit[N];
bool is_include(char *matrix, int rows, int cols, char *str, int i, int j, int k){

    if(i < 0 || j < 0 || i >= rows || j >= cols || subvisit[i * cols + j] ||
       (matrix[i * cols + j] != str[k] && str[k] != '\0'))
        return false;

    if(str[k + 1] == '\0') //run here means the last one has compared and equal.
        return true;

    subvisit[i * cols + j] = true;
    if(is_include(matrix, rows, cols, str, i - 1, j, k + 1) ||
       is_include(matrix, rows, cols, str, i, j - 1, k + 1) ||
       is_include(matrix, rows, cols, str, i, j + 1, k + 1) ||
       is_include(matrix, rows, cols, str, i + 1, j, k + 1))
        return true;

    subvisit[i * cols + j] = false;
    return false;
}

bool has_path(char *matrix, int rows, int cols, char* str, int i, int j){
    if(i < 0 || j < 0 || i >= rows || j >= cols || visited[i * cols + j])
        return false;

    memset(subvisit, 0, sizeof(subvisit));
    if(is_include(matrix, rows, cols, str, i, j, 0) == true)
        return true;
    visited[i * cols + j] = true;
    return has_path(matrix, rows, cols, str, i - 1, j) ||
        has_path(matrix, rows, cols, str, i, j - 1) ||
        has_path(matrix, rows, cols, str, i, j + 1) ||
        has_path(matrix, rows, cols, str, i + 1, j);
}

bool hasPath(char* matrix, int rows, int cols, char* str){
    memset(visited, 0, sizeof(visited));
    return has_path(matrix, rows, cols, str, 0, 0);
}

int main(void){

    /* char *matrix = "abcesfcsadee"; */
    /* char *str1 = "bcced"; */
    /* char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS"; */
    /* char *str1 = "SGGFIECVAASABCEHJIGQEM"; */
    char *matrix = "AAAAAAAAAAAA";
    char *str1   = "AAAAAAAAAAAA";
    printf("\nVISITED %d\n", hasPath(matrix, 3, 4, str1));
    return 0;
}
