// Program to find best buying and selling days
#include <stdio.h>
#include <string.h>

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
	int i, j, res;
	int count;

	// bit operate is the essence of the computer, because its the way of computer thinking 
	res = 0;
	for(i = 0; i < 32; i++){
		count = 0;
		for(j = 0; j < n; j++)
			if ((a[j] >> i) & 1)
				count++;
	
		count = count % 3;
		res |= count << i;
	}
	
	printf("res %d\n", res);
	return res;
}
 
// Driver program to test above functions
int main()
{
    // stock prices on consecutive days
    int A[] = {3, 3, 4, 4, 5, 5, 4, 9, 5, 3};
    int n = sizeof(A)/sizeof(A[0]);  //dynamic get it;
	
    // fucntion call
	single_number(A, n);
    return 0;
}

