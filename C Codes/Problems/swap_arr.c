#include<stdio.h>
int main()
{
    int arr[] = {1,2,3,4,5};
    int n=5;
    int k=3;
    int flag=1;
    int mid = n/2; 
    while(k--)
    {
        if(flag)
        {
            int temp = arr[n-1];
            for(int i=n-1;i>=mid;i--)
            {
                arr[i] = arr[i-1];
            }
            arr[mid] = temp;
        }
        else 
        {
            int temp = arr[0];
            for(int i=1;i<=mid;i++) arr[i-1] = arr[i];
            arr[mid] = temp;
        }
        flag = !flag;
    }
    printf("%d %d",arr[0],arr[n-1]);
}