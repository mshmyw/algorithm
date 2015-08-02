#include <stdio.h>
#include <stdlib.h>

int s[5];

int rand_int(double left,  double right){
	int T;
	T = left + (int)(right * rand()/(RAND_MAX+1.0)); 	
	/* printf("T %d--", T); */
	return T;
}

void my_sample(int M, int N){
	int i;
	int T;

	if(M == 0)
		return;
	
	my_sample(M - 1, N - 1);
	T = rand_int(1, N);
	for( i = 0; i < M - 1; i++)
		if(s[i] == T)
			break;
	if(i == (M - 1))
		s[M - 1] = T;
	else
		s[M -1] = N;

	return;
}

int main(void){
	int i;
	
	srand((int)time(0)); 	
	my_sample(5, 10);
	for(i = 0; i < 5; i++)
		printf("%d ", s[i]);
	return 0;
}
