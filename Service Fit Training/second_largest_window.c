#include<stdio.h>
#include<limits.h>
int secondLargest(int arr[],int start,int end)
{
    int n = 20;
    int max=INT_MIN;
    int second_max = INT_MIN;
    for(int i=start;i<=end;i++)
    {
        if(arr[i] > max)
        {
            second_max = max;
            max = arr[i];
        }
        else if(arr[i] > second_max)
        {
            second_max = arr[i];
        }
    }
    return second_max;
}
int main()
{
    int n = 20;
    int arr[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200};
    int k = 5;
    int start = 0;
    int end = k-1;
    while(end != n)
    {
        int ans = secondLargest(arr,start,end);
        printf("%d ",ans);
        start++;
        end++;
    }
}
