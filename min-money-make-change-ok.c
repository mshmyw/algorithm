#include <stdio.h>
#include <string.h>
#include <malloc.h>

int min(int a, int b){
	if (a <= b)
		return a;

	return b;
}

int max(int a, int b){
	if (a <= b)
		return b;

	return a;
}

void print(int a[], int n){
	int i;

	for (i = 0; i < n; i++){
		printf("(%3d %3d)  ", i, a[i]);
		if ((i + 1) % 2 == 0)
			printf("\n");
	}
	printf("\n");

	return;
}

void min_coin(int total_money, int v[], int kinds, int min_coin_value){

	int money, current;
	int min_num;

	int *num = (int *)malloc(sizeof(int) * (total_money + 1));
	
	memset((int *)num, 0xffffffff, (total_money + 1) * sizeof(int));
	num[0] = 0; //0元时候的方案为0

	//当money小于最小银币值又不为0时表明没有找零方案.NOTE:没有跟值为零是不同的含义
	for (money = 1; money < min_coin_value; money++)
		num[money] = -2;

	for (money = min_coin_value; money <= total_money; money++){
		min_num = (money / min_coin_value) + 1;
		for (current = 0; current < kinds; current++){
			/* 是:min(min_num, num[money - v[current]] + 1);而不是
				min(min_num, num[money - v[current]]) + 1;
			*/
			if ((money - v[current]) >= 0)//钱数合理
				if (num[money - v[current]] != -2)//没有方案
					min_num = min(min_num, num[money - v[current]] + 1);
		}
		num[money] = min_num;
	}

	print(num, total_money + 1);
	free(num);

	return;
}

// Driver program to test above functions
int main(){

	/* int total_money = 11; */
	/* int value[] = { */
	/* 	2, 3, 5 */
	/* }; */
	int total_money = 63;
	int value[] = {
		3, 5, 10, 22, 26
	};

	int kinds = sizeof(value) / sizeof(value[0]);  //dynamic get it;
	int min_coin_value = value[0];

	// fucntion call
	min_coin(total_money, value, kinds, min_coin_value);

	return 0;
}
