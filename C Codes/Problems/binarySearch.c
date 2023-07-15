#include<stdio.h>

int binarySearch(int *arr,int start,int end,int target)
{
    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) start = mid + 1;
        else if(arr[mid] > target) end = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int target = 70;
    printf("%d",binarySearch(arr,0,9,target));
}