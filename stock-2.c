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


void max_profit(int a[], int n){
	int i;
	int profit;
	int diff;
	
	profit = 0;
	
	for(i = 1; i < n; i++){
		diff = a[i] - a[i - 1];
		profit = profit + max(diff, 0);
	}
	
	printf(" %d\n", profit);
	/* print(profit, n); */
	return;
}

 
// Driver program to test above functions
int main()
{
    // stock prices on consecutive days
    int price[] = {800, 180, 260, 310, 40, 535, 695, 220};
    int n = sizeof(price)/sizeof(price[0]);  //dynamic get it;
	
    // fucntion call
	max_profit(price, n);
    return 0;
}
