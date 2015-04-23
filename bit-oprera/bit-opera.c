#include <stdlib.h>
#include <stdio.h>
int ones_bits(unsigned int x){
    int count = 0;
    int n = x;

    while(n){
        count++;
        n = n&(n - 1); /* set least signed bits(lsb) zero */
    }

    return count;
}

int ones_bits_2(unsigned int n){
    n=(n & 0x55555555) + ((n>>1) & 0x55555555);
    n=(n & 0x33333333) + ((n>>2) & 0x33333333);
    n=(n & 0x0f0f0f0f) + ((n>>4) & 0x0f0f0f0f);
    n=(n & 0x00ff00ff) + ((n>>8) & 0x00ff00ff);
    n=(n & 0x0000ffff) + ((n>>16) & 0x0000ffff);
    return n;
}

unsigned int /* spent time O(log32) */
leading_zero_count(unsigned int x){

    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);

    return ones_bits_2(~x);
}

#define WORDBITS 32

int min_2(int x, int y){

    return  x + ( ( (y - x) >> (WORDBITS - 1) ) & ( y - x ) );

}

unsigned int trailing_zero_count(unsigned int x){
    x = x | (x << 1);
    x = x | (x << 2);
    x = x | (x << 4);
    x = x | (x << 8);
    x = x | (x << 16);

    return ones_bits(~x);
}

unsigned int reverse_bit(unsigned int n){
    unsigned  int low_1  = 0b01010101010101010101010101010101;
    unsigned int high_1  = 0b10101010101010101010101010101010;
    unsigned int low_2   = 0b00110011001100110011001100110011;
    unsigned int high_2  = 0b11001100110011001100110011001100;
    unsigned int low_4   = 0b00001111000011110000111100001111;
    unsigned int high_4  = 0b11110000111100001111000011110000;
    unsigned int low_8   = 0b00000000111111110000000011111111;
    unsigned int high_8  = 0b11111111000000001111111100000000;
    unsigned int low_16  = 0b00000000000000001111111111111111;
    unsigned int high_16 = 0b11111111111111110000000000000000;

    n = ((n & low_1) << 1) | ((n & high_1) >> 1);
    n = ((n & low_2) << 2) | ((n & high_2) >> 2);
    n = ((n & low_4) << 4) | ((n & high_4) >> 4);
    n = ((n & low_8) << 8) | ((n & high_8) >> 8);
    n = ((n & low_16) << 16) | ((n & high_16) >> 16);

    return n;
}

unsigned int
reverse(register unsigned int x)
{
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 16) | (x << 16));

}

unsigned int longest_1_bits_string(unsigned int x){
    int count = 0;
    int n = x;

    while(n){
        n = n & (n << 1);
        count++;
    }

    return count;
}

int average(int x, int y)   //返回X、Y的平均值
{
     return (x & y) + ( (x^y)>>1 );
     //x&y  取出x和y二进制都为 1 的所有位，这是x、y都为 1 的部分，因为相同，所以直接加就行了
     //x^y  x和y中有一个为 1 的所有位
     //后者是x为 1，y为 0的部分，以及y为 1，x为 0 的部分，两部分加起来除以2，然后跟前面的相加就可以了
}

int abs_negative(int n){
    int i = n >> 31;
    return ((n^i) - i);
}

int add_recur(int x, int y){
    if(y == 0)
        return x;

    return add_recur(x ^ y, (x & y) << 1);
}

int a_b_add(int x, int y){
    int sum, conflict;
    do{
        sum = x ^ y;
        conflict = (x & y) << 1;
        x = sum;
        y = conflict;
    }while(conflict);

    return sum;
}

int main()
{
    unsigned int num[] = {3, 2, 4};
    unsigned int n = sizeof(num) / sizeof(num[0]);
    unsigned int i;
    unsigned int rnum;
    for(i = 0; i < n; i++){
        rnum = reverse_bit(num[i]);
        printf("(%u, %u)\n", num[i], rnum);
    }

    unsigned int x = 6;
    int lzc = leading_zero_count(x);
    printf("\nlzc: %d\n", lzc);
    int tzc = trailing_zero_count(x);
    printf("\ntzc: %d\n", tzc);

    printf("abs: %d\n", abs_negative(-3));

    unsigned int xx = 0b00111101001111011111110100111101;
    unsigned int count_1_length = longest_1_bits_string(xx);
    printf("longest 1 bits string %u \n", count_1_length);

    printf("average: %d\n", average(4, 12));

    printf("min_2 %d\n", min_2(12, 23));

    /* int sum = a_b_add(4, 5); */
    int sum = add_recur(4, -5);
    printf("sum %d\n", sum);

    return 0;
}

void swap(int *a, int *b){
    if(*a == *b)return;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

    return;
}
