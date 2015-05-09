#include <stdio.h>
#include <stdlib.h>
void print(int a, int b){
    printf("(%d, %d)\n", a, b);
}
#define BIG_CUP    4
#define LITTLE_CUP 2
void push_water(int big_cup_water, int little_cup_water, int target){
    if(big_cup_water == target){
        print(big_cup_water, little_cup_water);
        return;
    }
    print(big_cup_water, little_cup_water);
    big_cup_water = (big_cup_water + little_cup_water) % BIG_CUP;
    push_water(big_cup_water, little_cup_water, target);
}

int main(void){
    int big_cup_water = BIG_CUP;
    int little_cup_water = LITTLE_CUP;
    int target = 3;
    push_water(big_cup_water, little_cup_water, target);
	
	return 0;
}
