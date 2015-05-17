#include<stdio.h>
#include<stdlib.h>

int major_find(int *a, int n){
    int count = 1;
    int candidate = a[0];
    int i;

    for(i = 0; i < n; i++){
        if(candidate == a[i])
            count++;
        else{
            if(count == 0){
                count = 1;
                candidate = a[i];
            }else
                count--;
        }
    }
    count = 0;
    for(i = 0; i < n ; ++i)
        if(a[i] == candidate)
            count++;
    if(count > (n / 2))
        return candidate;

    return -1;
}

int main(void){
    int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);

    int major_element = major_find(a, n);
    if(major_element != -1 )
        printf("major-element %d\n", major_element);
    else
        printf("no major-element\n");
    return 0;
}
