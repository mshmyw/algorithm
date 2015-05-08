#include<stdio.h>
#include<stdlib.h>

void combinate_sum(int *com, int n, int *count, int sum){
    if(sum == 0){
        (*count)++;
        return;
    }
    if(sum < 0)
        return;

    combinate_sum(com, n, count, sum - com[0]);
    combinate_sum(com, n, count, sum - com[1]);

    return;
}

int main(void){
    int com[] = {3, 4};
    int n = sizeof(com) / sizeof(com[0]);
    int count = 0;
    int sum = 12;
    combinate_sum(com, n, &count, sum);
    printf("count: %d\n", count);

    return 0;
}
