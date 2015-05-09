// Program to find best buying and selling days
#include <stdio.h>
#include <malloc.h>

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
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    return;
}

int average(int a, int b){

    return ((a & b) + ((a ^ b) >> 1));
}


double find_kth(int a[], int m, int b[], int n, int k)  {  
    //always assume that m is equal or smaller than n  
    if (m > n)  
        return find_kth(b, n, a, m, k);  
    if (m == 0)  
        return b[k - 1];  
    if (k == 1)  
        return min(a[0], b[0]);  
    //divide k into two parts  
    int pa = min(k / 2, m), pb = k - pa;  
    if (a[pa - 1] < b[pb - 1])  
        return find_kth(a + pa, m - pa, b, pb, k - pa);
        /* return find_kth(a + pa, m - pa, b, n, k - pa);   */
    else if (a[pa - 1] > b[pb - 1])  
        return find_kth(a, pa, b + pb, n - pb, k - pb);
        /* return find_kth(a, m, b + pb, n - pb, k - pb);   */
    else  
        return a[pa - 1];  
}  
  
double find_median_sorted_array(int A[], int m, int B[], int n){  
    int total = m + n;  
    if (total & 0x1)  
        return find_kth(A, m, B, n, total / 2 + 1);  
    else  
        return (find_kth(A, m, B, n, total / 2)  
                + find_kth(A, m, B, n, total / 2 + 1)) * 1.0 / 2;  
}  
// Driver program to test above functions
int main(){
    
    // stock prices on consecutive days
    int price1[] = {2, 4, 7, 9, 14};
    int price2[] = {0, 5, 10, 11, 12};
    int m = sizeof(price1)/sizeof(price1[0]);  //dynamic get it;
    int n = sizeof(price2)/sizeof(price2[0]);  //dynamic get it;
    // fucntion call
    /* quick_sort(price, n); */
    double median = find_median_sorted_array(price1, m, price2, n);
    printf("median %lf\n", median);
    return 0;
}
