#include<stdio.h>
int calculateGCD(int a,int b)
{
    while(b!=0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int calculateLCM(int a,int b)
{
    int gcd = calculateGCD(a,b);
    int lcm = (a*b)/gcd;
    return lcm;
}
int main()
{
    int a = 5;
    int b = 10;
    printf("%d",calculateLCM(a,b));
}