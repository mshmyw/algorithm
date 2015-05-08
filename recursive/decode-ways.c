#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define   N  3

void print(int s[], int n){
	int i;

	for(i = 0; i < n; i++)
		printf("%d ", s[i]);
	printf("\n");
	
	return;
}

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

 int climb_stairs(int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
 
    return climb_stairs(n - 1) + climb_stairs(n - 2);
}

int climb_stairs_iter(int n){
    int *f = malloc(sizeof(int) * (n + 1));
    int i;
    f[0] = f[1] = 1;//0时默认为1
    f[2] = 2;
    
    for(i = 3; i < n + 1; i++)
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];

    return f[i - 1];
}

int main(void){

    int count = climb_stairs(6);
    printf("count: %d\n", count);

    count = climb_stairs_iter(10);
    printf("count: %d\n", count);
	return 0;
}
