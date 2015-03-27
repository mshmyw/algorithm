#include <stdio.h>
#include <stdlib.h>
#define   N  3

void print(int s[], int n){
	int i;

	for(i = 0; i < n; i++)
		printf("%d ", s[i]);
	printf("\n");
	
	return;
}
void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void  my_permutation(int a[], int i, int n){
	int j;

	if(i == n){
		print(a, n);
		return;
	}

	for(j = i; j < n; j++){
		swap(&a[i], &a[j]);
		my_permutation(a, i + 1, n);
		swap(&a[i], &a[j]);
	}

	return;
}

int main(void){
	int i;
	int a[N] = {
		3, 1, 2
	};
	my_permutation(a, 0, N);

	return 0;
}
