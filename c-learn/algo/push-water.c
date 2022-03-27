#include <stdio.h>
#include <stdlib.h>
void print(int a, int b){
    printf("(%d, %d)\n", a, b);
}
#define BIG_CUP    8
#define LITTLE_CUP 5
void push_water(int big_cup_water, int little_cup_water, int target){
    if(big_cup_water == target){
        print(big_cup_water, little_cup_water);
        return;
    }
    print(big_cup_water, little_cup_water);
    big_cup_water = (big_cup_water + little_cup_water) % BIG_CUP;
    push_water(big_cup_water, little_cup_water, target);
}

void move(char a, char c, int n){
       printf("move %d from %c to %c \n", n, a, c);
       return;
}

void hanoi(char a, char b, char c, int n){ // move a to c by b
    if(n == 1){
        move(a, c, n);
        return;
    }

    hanoi(a, c, b, n - 1);
    move(a, c, n);
    hanoi(b, a, c, n - 1);
    return;
}

int main(void){
    int big_cup_water = BIG_CUP;
    int little_cup_water = LITTLE_CUP;
    int target = 4;
    /* push_water(big_cup_water, little_cup_water, target); */
    char a = 'a';
    char b = 'b';
    char c = 'c';
    int n = 3;
    hanoi(a, b, c, n);
    
	return 0;
}
