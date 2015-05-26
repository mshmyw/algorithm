#include<stdio.h>

int ysf_i_th(int n, int step, int i_th){ // only necessary is n(the number of people), not the array.
    if(i_th == 1)
        return (n + step - 1) % n;

    return (step + ysf_i_th(n - 1, step, i_th - 1)) % n;
}

int ysf(int n, int step){
    if(1 == n)
        return 0;
    return (ysf(n - 1, step) + step) % n;
}

int main(){

    int i;
    for(i = 1; i <= 10; i++){
       int j =  ysf_i_th(10, 3, i);
       printf("the %d times is %d\n", i, j);
    }

    int alive = ysf(10, 3);
    printf("alive %d\n", alive);

    return 0;
}
