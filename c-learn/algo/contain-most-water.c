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


void max_water_O_n(int a[], int n){
	int i, j;

	int contain;
	int res;
    res = 0;
	for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            contain = (j - i) * min(a[j], a[i]);
            res = max(res, contain); 
        }

	}
}

void max_water(int a[], int n){
	int i, j;
	int contain;
	int res;
    
    i = 0;
    j = n - 1;
    res = (j - i) * min(a[j], a[i]);

    while(i < j){
        if(a[i] == min(a[i], a[j]))
            i++;
        else
            j--;
        res = max(res, (j - i) * min(a[j], a[i]));            
 	}
	
	printf(" %d\n", res);
	/* print(profit, n); */
	return;
}

 
// Driver program to test above functions
int main()
{
    // stock prices on consecutive days
    int price[] = {8, 4, 2, 7, 3, 9};
    int n = sizeof(price)/sizeof(price[0]);  //dynamic get it;
	
    // fucntion call
	max_water(price, n);
    return 0;
}
