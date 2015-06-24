//file name : word-maze.c
//created at: Wed Jun 24 19:17:10 2015
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

void print(char *a, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%2c", a[i]);

    printf("\n");

    return;
}

#define N 5
char *ma[N] = {"WHATY",
               "OURFO",
               "ROMRU",
               "ODEEC",
               "FODNA"};

void walk_word_maze_inner(int i, int j, int pre_i, int pre_j, char *key){

    if(i < 0 || i >= 5 || j < 0 || j >= 5){
        printf("NO\n");
        return;
    }

    if(ma[i][j] == *key){

        if(*(key + 1) == '\0'){ // forward predict one char
            printf("YES\n");
            return;
        }

        int next_i = i;
        int next_j = j;

        if(i != pre_i){
            if(i > pre_i) next_i++; // down
            else next_i--; // up

            walk_word_maze_inner(next_i, j, i, j, key + 1); // up or down
            walk_word_maze_inner(i, j + 1, i, j, key + 1);  // right
            walk_word_maze_inner(i, j - 1, i, j, key + 1);  // left
            return;
        }

        if(j != pre_j){
            next_j = j;
            if(j > pre_j) next_j++; // right
            else next_j--; // left

            walk_word_maze_inner(i, next_j, i, j, key + 1); // right or left
            walk_word_maze_inner(i + 1, j, i, j, key + 1);  // down
            walk_word_maze_inner(i - 1, j, i, j, key + 1);  // up
            return;
        }
    }

    return;
}

void walk_word_maze(char *key){

    int i, j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(ma[i][j] == *key){
                walk_word_maze_inner(i + 1, j, i, j, key + 1);
                walk_word_maze_inner(i - 1, j, i, j, key + 1);
                walk_word_maze_inner(i, j + 1, i, j, key + 1);
                walk_word_maze_inner(i, j - 1, i, j, key + 1);
                break;
            }
    return;
}

int main(void){

    int i;
    for(i = 0; i < N; i++)
        print(ma[i], N);

    char *key = "WHATYOUCANDOFOROURFREEDOM"; //the snake hydra
    /* char *key = "WHAT"; //the snake hydra */
    walk_word_maze(key);

    return 0;
}
