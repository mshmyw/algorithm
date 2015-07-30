//file name : buy-book.c
//created at: Wed Jul 29 16:30:21 2015
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
    if(a == 0 || b == 0)
        return max(a, b);

    return a > b ? b : a;
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

void min_num(int *num, int kinds, int *min_value, int *count){
    int i;
    assert(num != NULL && kinds > 0);
    *min_value = num[0];
    for(i = 0; i < kinds; i++){
        if(num[i] > 0)
            *count += 1;

        *min_value = min(*min_value, num[i]);
    }

    return;
}

bool no_book(int *num, int kinds){
    int i;
    for(i = 0; i < kinds; i++)
        if(num[i])
            return false;

    return true;
}

void get_part_money(int price, int min_value, int count, float *discount, float *part_money){

    *part_money = (float)(price * min_value * count * (1 - discount[count - 1]));
    printf("--count-%d-part-money--%f\n", count, *part_money);
    return;
}

void buy_book_recur(int price, int *num, int kinds, float *discount, float *money){
    if(no_book(num, kinds))
        return;

    print(num, kinds);
    int min_value, count = 0;
    min_num(num, kinds, &min_value, &count);
    printf("--count-%d-min value--%d\n", count, min_value);
    //TODO get the money
    float part_money = 0.0;
    get_part_money(price, min_value, count, discount, &part_money);
    *money += part_money; //calculate

    int i;
    for(i = 0; i < kinds; i++)
        if(num[i] > 0)
            num[i] -= min_value;

    buy_book_recur(price, num, kinds, discount, money);
    return;
}

void buy_book(int price, int *num, int kinds, float *discount, float *money){
    if(num == NULL)
        return;

    buy_book_recur(price, num, kinds, discount, money);
    return;
}

int main(void){
    /* int num[] = { 3, 2, 4, 5, 7}; */
    int num[] = { 2, 2, 2, 1, 1};
    float discount[] = {0, 0.05, 0.1, 0.2, 0.25};
    int n = sizeof(num) / sizeof(num[0]);

    int price = 8;
    float money = 0.0;
    buy_book(price, num, n, discount, &money);
    printf("the least money you must pay is =%f= ^=^\n", money);
    return 0;
}
