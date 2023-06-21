#include<stdio.h>
#include<math.h>
int isprime(int n)
{
    if(n==2 || n==3) return 1;
    if(n%2==0 || n%3==0) return 0;
    for(int i=5;i<n;i=i+2)
    if(n%i==0) return 0; 
    return 1;
}
int leftTruncate(int n)
{
    int temp = n;
    int rem = 10;
    while(temp)
    {
        int res = n%rem;
        if(isprime(res)) 
        {
            //printf("%d ",res);
            temp/=10;
        }
        else return 0;
        rem = rem*10;
    }
    return 1;
}
int rightTruncate(int n)
{
    if(n%2==0) return 0;
    while(n)
    {
        if(isprime(n)) 
        {
            //printf("%d ",n);
            n/=10;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    int n = 71933;
    if(leftTruncate(n)) printf("LEFT TRUNCATE");
    else if(rightTruncate(n)) printf("RIGHT TRUNCATE");
    else printf("NEITHER");
}