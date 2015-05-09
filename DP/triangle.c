/*
Author: msh
Blog:   www.WuTianQi.com
Description: 动态规划之三角形求值问题
*/
#include <stdio.h>
#include <string.h>
 
int map[6][6] = 
{
	{0, 0, 0, 0, 0, 0},
	{0, 7, 0, 0, 0, 0},
	{0, 3, 8, 0, 0, 0},
	{0, 8, 1, 0, 0, 0},
	{0, 2, 7, 4, 4, 0},
	{0, 4, 5, 2, 6, 5}
};
 
int f[6][6];
 
int _max(int a, int b)
{
	if(a >= b)
		return a;
	return b;
}
 
int main(){
	int i, j;

	memset(f, 0, sizeof(f));
	for(i = 0; i < 6; ++i)
		f[5][i] = map[5][i];
	for(i = 4; i >= 1; --i)
		for(j = 1; j <= i; ++j)
			f[i][j] = _max(f[i+1][j], f[i+1][j+1]) + map[i][j];
	
	for(i = 1; i <= 5; ++i){
		for(j = 1; j <= 5; ++j)
			printf(" %d ", f[i][j]);
		printf("\n");
	}

	printf("% d", f[1][1]);

	return 0;
}
