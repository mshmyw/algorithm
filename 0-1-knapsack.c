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
		printf(" %2d", a[i]);
	printf("\n");

	return;
}

#define N 5
#define W 10000
int cost[N] = {6, 4, 5, 3, 6};
int weight[N] = {4, 5, 6, 2, 2};
int c[N + 1][W + 1];
void knapsack_old(int n, int w){
    int i, j;
    memset(c, 0, sizeof(c));
    //初始值
    for(j = 0; j <= w; j++)
        if( j < weight[0])
            c[0][j] = 0;
        else
            c[0][j] = cost[0];

    for( i = 1; i < n; i++)
        for(j = 0; j <= w; j++)
            if(j - weight[i] < 0)
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = max(c[i - 1][j], c[i - 1][j - weight[i]] + cost[i]);

    printf("most values %d\n", c[n - 1][w]);
}

//完全背包
void knapsack(int n, int w){
    int dp[W + 1];
    int i, j;
    memset(dp, 0, sizeof(dp));

    for( i = 0; i < n; i++)
        for(j = weight[i]; j <= w; j++)
            dp[j] = max(dp[j], dp[j - weight[i]] + cost[i]);

    printf("most values %d\n", dp[w]);

    print(dp, w + 1);
}

int knapsack_recur(int n, int w){

    if(0 == n)
        return (w < weight[n]) ? 0 : cost[0];

    if(c[n][w])
        return c[n][w];

    if(w - weight[n] < 0)
        return c[n][w] = knapsack_recur(n - 1, w);
    else
        return  c[n][w] = max(knapsack_recur(n - 1, w), knapsack_recur(n - 1, w - weight[n]) + cost[n]);
}


// Driver program to test above functions
int main()
{
    int w = 10;
    int i, j;
    
    memset(c, 0, sizeof(c));
    //��ʼֵ
    for(j = 0; j <= w; j++)
        if( j < weight[0])
            c[0][j] = 0;
        else
            c[0][j] = cost[0];
    
    // fucntion call
	knapsack_old(N, w);
	knapsack(N, w);
    /* knapsack_recur(1, w); */
    
    for(i = 0; i < N; i++){
        for(j = 0; j <= w; j++)
            printf(" %2d", c[i][j]);
        printf("\n");
    }
    return 0;
}
