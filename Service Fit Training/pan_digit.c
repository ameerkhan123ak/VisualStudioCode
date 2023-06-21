#include<stdio.h>
int main()
{
    long long int n = 123456789;
    int arr[10] = {0};
    while(n)
    {
        arr[n%10] += 1;
        n/=10;
    }
    int flag=1;
    for(int i=1;i<10;i++)
    {
        if(arr[i]==0) 
        {
            flag=0;
            break;
        }
    }
    if(flag) printf("TRUE");
    else printf("FALSE");
}