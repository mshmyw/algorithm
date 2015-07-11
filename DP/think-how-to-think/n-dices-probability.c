//file name : n-dices-probability.c
//created at: Sat Jul 11 19:21:15 2015
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

#define MAX_DOT 6 // the dice max value
void get_n_dices_probability_inner(int n, int cur_n, int *probability, int sum){
    if(cur_n == 0){
        probability[sum - n]++;
        return;
    }

    int i;
    for(i = 1; i <= MAX_DOT; i++)
        get_n_dices_probability_inner(n, cur_n - 1, probability, sum + i);

    return;
}

void n_dices_probability_inner(int n, int *probability){

    int sum = 0;
    int cur_n = n;
    get_n_dices_probability_inner(n, cur_n, probability, sum);

    return;
}

void n_dices_probability(int n){
    int *probability = malloc(sizeof(int) * (6 * n - n + 1));
    memset(probability, 0, sizeof(int) * (6 * n - n + 1));

    n_dices_probability_inner(n, probability);

    int total = pow((double) MAX_DOT, n);
    int i;
    for(i = n; i <= 6 * n; i++){
        double pro = probability[i - n] / (double)total;
        printf("%d %d => %lf \n", i, probability[i - n], pro);
    }

    return;
}

int main(void){

    int n = 2;
    n_dices_probability(n);

    return 0;
}
