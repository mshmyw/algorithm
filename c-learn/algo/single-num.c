// Program to find best buying and selling days
#include <stdio.h>
int min(int a, int b){
	if(a <= b)
		return a;
	
	return b;
}

int max(int a, int b){
	if(a <= b)
		return b;
	
	return a;
}

void print(int a[], int n){
	int i;
	
	for(i = 0; i < n; i++)
		printf(" %d", a[i]);
	printf("\n");

	return;
}

void swap(int *a, int *b){
	
	int t = *a;
	*a = *b;
	*b = t;
	
	return;
}
int single_number(int a[], int n) {
	int i, res;
	
	res = a[0];
	// it's amazing!!
	for(i = 1; i < n; i++)
		res ^= a[i];
	
	printf("res %d\n", res);
	return res;
}
 
// Driver program to test above functions
int main()
{
    // stock prices on consecutive days
    int A[] = {3, 4, 5, 5, 4, 3, 2};
    int n = sizeof(A)/sizeof(A[0]);  //dynamic get it;
	
    // fucntion call
	single_number(A, n);
    return 0;
}

