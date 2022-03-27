#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void my_sqrt(double n, double a){
	
	double b = (a + (n / a)) / 2;
	printf("b %lf\n", b);
	
	if(fabs(a - b) < (1.0e-16)){
		printf("<%lf %lf>---\n", n, b);
		return;
	}
	
	my_sqrt(n, b);
	
	return;
}
int main(void){
	int i;
	int a[N] = {
		3, 1, 2
	};
	/* my_permutation(a, 0, N); */
	my_sqrt(2.0, 1000.0);
	return 0;
}
