#include<stdio.h>
char *p;
inline void Swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Perm(char list[],int start,int end)//Perm(str, 0,3);
{
	int i;
	
	if(start == end) //即此时集合里只有一个元素
		{
			for(i=0; i<=end; i++)
				printf("%c",*(p+i));
			printf("\n");
		}
	else
		{
			for(i= start; i<= end; i++)
				{
					Swap(p+start, p+i);//交换可得：1,{2,3,4} ; 2,{1,3,4};  3,{1,2,4}; 4,{1,2,3}
					Perm(p, start+1, end);
					Swap(p+start, p+i);//输出排列之后，要再交换回到初始状态:{1,2,3,4}
				}
		}
}
int main() 
{
	char str[] = "abcd";
	p=str;
	Perm(str, 0,3);
	return 0;
}
