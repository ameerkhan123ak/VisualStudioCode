#include<stdio.h>

int factorial(int n)
{
    int fact = 1;
    while(n>=1)
    {
        fact = fact * n;
        n--;
    }
    return fact;
}
int main()
{
    int n; // number of rows
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int k=i;k<=n;k++) printf(" ");
        for(int j=0;j<=i;j++)
        {
            int term = factorial(i) / (factorial(j) * factorial(i-j));
            printf(" %d ",term);
        }
        printf("\n");
    }
}