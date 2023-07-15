/*
The algorithm repeatedly selects the smallest (or largest) element from the unsorted portion of the list and 
swaps it with the first element of the unsorted part.
 This process is repeated for the remaining unsorted portion until the entire list is sorted. 

 Time Complexity: O(N*N)
 Space Complexity: O(1)
*/

#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int minIndex = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[minIndex])
            minIndex = j;
        }
        swap(&arr[i],&arr[minIndex]);
    }
}
int main()
{
    int arr[] = {50,40,30,20,10};
    int n=5;
    selectionSort(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

