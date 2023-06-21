#include<stdio.h>
int countBits(int x)
{
    int n = 0;
    while(x)
    {
        n += x & 1;
        x >>= 1;
    }
    return n;
}
int main()
{
    int a = 5;
    printf("%d",countBits(a));
}