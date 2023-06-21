#include<stdio.h>
int main()
{
    int arr[] = {0,1,0,3,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = n-1;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            arr[++index] = arr[i];
        }
    }
    for(int i=++index;i<n;i++) arr[i] =0;
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}