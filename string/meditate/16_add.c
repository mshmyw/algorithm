#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int str_len(char *a, int *len){
	int i;
	for(i = 0; a[i] != '\0'; i++);

	*len = i;

	return *len;
}

void reverse_str(char *a, int len){
	int i, j;

	for(i = 0, j= len - 1; i < j; i++, j--){
		char tmp = a[i]; a[i] = a[j]; a[j] = tmp;
	}

	return;
}

int str_to_num(char a, int *num){ // 0 <= num <= 15
		int x;
		if((0<= a - '0') && (a - '0' <= 9))
			x = a - '0';
		else 
			x = a - 'a' + 10;
		
		*num = x;

		return *num;
}

int func(char *a, char *b){
	int len1, len2, i, j, cnt;
	cnt = 0;
	str_len(a, &len1);
	str_len(b, &len2);

	char res[128];
	int flag = 0;
	memset(res, 0, sizeof(res));
	for(cnt = 0, i = len1 - 1, j = len2 - 1; (i >= 0) && (j >= 0); i--, j--, cnt++){
		int x, y, z;
		str_to_num(a[i], &x);
		str_to_num(b[j], &y);
		z = x + y + flag;
		res[cnt] = ((z % 16) > 9 ? (z % 16) + 'a' - 10 : (z % 16) + '0');
		flag = z / 16;
	}
	
	char *c = ((i < 0)? b: a);
	int index = ((i < 0)? j: i);
	for(; index >= 0; index--, cnt++){
			int x;
			str_to_num(c[index], &x);
			x = x + flag;
			res[cnt] = ((x % 16) > 9 ? (x % 16) + 'a' - 10 : (x % 16) + '0');
			flag = x / 16;
	}

	reverse_str(res, cnt);

	strncpy(a, res, sizeof(res));

	return cnt;
}

int main(){
	
	char a[128] = "35ad";
	char *b = "cdf";
	
	printf("****16 decimal add****\n");
	printf("0x%s + 0x%s = 0x", a, b);
	func(a, b);
	printf("%s\n", a);

	return 0;
}
