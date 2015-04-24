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

int average(int a, int b){

    return ((a & b) + ((a ^ b) >> 1));
}

void merge_left_right(int *data, int left, int mid, int right){
    int *temp = malloc(sizeof(int) * (right - left + 1));
    int i, j, k;
    
    for(i = left, j = mid + 1, k = 0; (i <= mid) && (j <= right); k++){
        temp[k] = min(data[i], data[j]);
        (temp[k] == data[i]) ? i++ : j++;
    }
    
    while(j <= right) temp[k++] = data[j++];
    while(i <= mid) temp[k++] = data[i++];

    for(j = 0; j < k; j++)
        data[left + j] = temp[j];

    free(temp);
    temp = NULL;
    return;
}
void merge_sort_inner(int *data, int left, int right){

    if(left >= right)
        return;

    int mid = average(left, right);

    merge_sort_inner(data, left, mid);
    merge_sort_inner(data, mid + 1, right);
    
    merge_left_right(data, left, mid, right);

    return;
}
void merge_sort(int *data, int n){
    merge_sort_inner(data, 0, n - 1);

    return;
}
 
// Driver program to test above functions
int main()
{
    // stock prices on consecutive days
    int price[] = {27, 2, 7, 72, 4, 3, 2, 2, 7, 1, -3, 0, 5, 10,1,1,2};
    int n = sizeof(price)/sizeof(price[0]);  //dynamic get it;
	
    // fucntion call
    /* quick_sort(price, n); */
    print(price, n);
    printf("--merge sort--\n");
    merge_sort(price, n);
    print(price, n);
    return 0;
}
