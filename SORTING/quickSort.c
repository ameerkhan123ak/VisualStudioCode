/*
The key process in quickSort is a partition(). 
The target of partitions is to place the pivot (any element can be chosen to be a pivot)
 at its correct position in the sorted array and put all smaller elements to the left of the pivot, 
 and all greater elements to the right of the pivot.

Partition is done recursively on each side of the pivot after 
the pivot is placed in its correct position and this finally sorts the array.

Time Complexity: O(N * log(N))
Space Complexity: O(log(N))
*/
#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr,int start,int end)
{
    int pivot = arr[end];
    int pivotIndex = start-1;
    for(int i=start;i<end;i++)
    {
        if(arr[i] <= pivot)
        {
            pivotIndex++;
            swap(&arr[pivotIndex],&arr[i]);
        }
    }
    swap(&arr[end],&arr[++pivotIndex]);
    return pivotIndex;
}
void quickSort(int *arr,int start,int end)
{
    if(start < end)
    {
        int pivotIndex = partition(arr,start,end);
        quickSort(arr,start,pivotIndex-1);
        quickSort(arr,pivotIndex+1,end);
    }
}
int main()
{
    int arr[] = {70,60,50,40,30,20,10};
    int n=7;
    quickSort(arr,0,6);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}
