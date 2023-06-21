#include<stdio.h>
int main()
{
    int n,mask;
    scanf("%d",&n);
    mask = 0x8000;
    while((mask & n)!=mask)
    {
        mask = mask >> 1;
    }
    while(mask)
    {
        n = n ^ mask;
        mask = mask>>1;
    }
    printf("%d",n);
}