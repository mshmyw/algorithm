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
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    return;
}

int get_pivot(int *data, int left_index, int right_index){
    int i;
    int m = left_index;
    
    for(i = left_index + 1; i <= right_index; i++)
        if(data[i] < data[left_index]){
            m++;
            swap(&data[m], &data[i]);
        }
    swap(&data[left_index], &data[m]);

    return m;
}

void quick_sort_inner(int *data, int left_index, int right_index){

    if(left_index >= right_index)
        return;
    
    int pivot_index = get_pivot(data, left_index, right_index);
    quick_sort_inner(data, left_index, pivot_index - 1);
    quick_sort_inner(data, pivot_index + 1, right_index);
    return;
}

void quick_sort(int *data, int n){

    quick_sort_inner(data, 0, n - 1);

    return;
}

 
// Driver program to test above functions
int main()
{
    // stock prices on consecutive days
    int price[] = {4, 3, 2, 2, 7, 1, -3, 0, 5, 10,1,1,2};
    int n = sizeof(price)/sizeof(price[0]);  //dynamic get it;
	
    // fucntion call
    quick_sort(price, n);
    print(price, n);

    return 0;
}
