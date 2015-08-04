//file name : min-steps-lift.c
//created at: Tue Aug  4 14:42:56 2015
//author:  root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0

typedef struct _PEOPLE{
    int *people_each_level;
    int nums_dst_levels;
    int max_level;
}PEOPLE;

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
        printf("%3d", i);
    printf("\n");

    for(i = 0; i < n; i++)
        printf("%3d", a[i]);
    printf("\n");

    return;
}

void init_people(int *dst_levels, int n, int *people_each_level, int max_level, PEOPLE *people, int *total_steps){
    assert(dst_levels && people_each_level && n > 0);

    int i, tmp_steps = 0;
    people->people_each_level = (int *)malloc(sizeof(int) * (max_level + 1));
    memset(people->people_each_level, 0, sizeof(int) * (max_level + 1));
    for(i = 0; i < n; i++){
        people->people_each_level[dst_levels[i]] = people_each_level[i];
        tmp_steps += dst_levels[i] * people_each_level[i];
    }

    print(people->people_each_level, max_level + 1);
    people->nums_dst_levels = n;
    people->max_level = max_level;
    *total_steps = tmp_steps;
    return;
}

void get_diff(PEOPLE *people, int **diff){
    assert(people);
    int max_level = people->max_level;
    *diff = (int *)malloc(sizeof(int) * (max_level + 1));
    int *pdiff = *diff;
    memset(pdiff, 0, sizeof(int) * (max_level + 1));
    int i, total_people = 0;
    for(i = 0; i < people->max_level; i++)
        total_people += people->people_each_level[i];
    int n1 = 0;
    int n2 = total_people;
    for(i = 0; i < max_level; i++){
        n1 += people->people_each_level[i];
        n2 = total_people - n1;
        pdiff[i] = n1 - n2;
    }
    return;
}
void get_min_results(int total_steps, int *diff, int max_level, int *min_results){
    int *res_every_level = (int *)malloc(sizeof(int) * (max_level + 1));
    memset(res_every_level, 0, sizeof(int) * (max_level + 1));

    res_every_level[0] = total_steps;
    int i;
    int tmp_min= total_steps;
    for(i = 1; i < max_level + 1; i++){
        res_every_level[i] = res_every_level[i - 1] + diff[i - 1];
        tmp_min = min(tmp_min, res_every_level[i]);
    }

    *min_results = tmp_min;
    print(res_every_level, max_level + 1);
    printf("MIN %d\n", *min_results);

    free(res_every_level);
    return;
}
int main(void){

    int dst_levels[] = {2, 3, 5, 7};
    int people_each_level[] = {4, 1, 6, 3};
    int n = sizeof(dst_levels) / sizeof(dst_levels[0]);
    int max_level = 10;
    PEOPLE people;
    int total_steps;
    init_people(dst_levels, n, people_each_level, max_level, &people, &total_steps);
    printf("--INIT--\n");
    int *diff; // means nums of people of equal or less than i - nums of people greater than i
    get_diff(&people, &diff);
    print(diff, max_level);

    int min_results = 0;
    get_min_results(total_steps, diff, max_level, &min_results);

    free(diff);
    free(people.people_each_level);
    return 0;
}
