//file name : maze-path.c
//created at: Sun Aug  9 14:46:07 2015
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

#define M 5
#define N 5
/* int maze[M][N] = { */
/* 0, 1, 0, 0, 0, */
/* 0, 1, 0, 1, 0, */
/* 0, 0, 0, 0, 0, */
/* 0, 1, 1, 1, 0, */
/* 0, 0, 0, 1, 0, */
/* }; */

int maze[M][N] = {
0, 1, 0, 0, 0,
0, 1, 0, 1, 0,
0, 0, 0, 0, 0,
0, 1, 0, 1, 0,
0, 0, 0, 0, 0,
};

typedef struct _POINT{
    int x;
    int y;
}POINT;
POINT point[M + N];

void print_path(POINT *point, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("(%d, %d)->", point[i].x, point[i].y);

    return;
}

void maze_path(int i, int j, int k){
    if((i == M - 1) && (j == N - 1) && maze[i][j] == 0){
        point[k].x = i;
        point[k].y = j;
        print_path(point, k + 1);
        printf("WALK OK\n");
        return;
    }

    if(i == M || j == N) //row and column valid border
        return;
    if(maze[i][j] == 1) //wall can't walk
        return;

    if(maze[i][j] == 0){ //normal
        point[k].x = i;
        point[k].y = j;
        maze_path(i + 1, j, k + 1); // down
        maze_path(i, j + 1, k + 1); // down
    }

}

int main(void){
    memset(point, -1, sizeof(point));
    maze_path(0, 0, 0);

    return 0;
}
