#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define   N  5

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
int internal_select(int a[], int left, int right){
	int i, j, t;
	
	t = a[left];
	j = left;
	
	for(i = left + 1; i <= right; i++)
		if(a[i] < t){
			j++;
			swap(&a[i], &a[j]);
		}			
	swap(&a[j], &a[left]);

	return j;
}


void select_kth(int a[], int left,int right, int k){
	int m;
	
	/* if(left >= right) */
	/* 	return; */
	print(a, N);
	m = internal_select(a, left, right);
	/* printf("m: %d, left: %d, right: %d\n", m, left, right); */
	/* print(a, N); */

	if(k < m)
		select_kth(a, left, m - 1, k);
	else if(k > m)
		select_kth(a, m + 1, right, k);
	else{
		printf("<%d, %d>\n", k, a[k]);
		return;
	}

	return;
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
		2, 4, 6, 3, 1
	};
	/* my_permutation(a, 0, N); */
	/* my_sqrt(2.0, 1000.0); */
	select_kth(a, 0, N - 1, 4);  //here is N - 1, not N
	print(a, N);
	return 0;
}
