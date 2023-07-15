/*
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. 
The array is virtually split into a sorted and an unsorted part.
 Values from the unsorted part are picked and placed at the correct position in the sorted part.

 Time Complexity: O(N^2) 
 Auxiliary Space: O(1)
*/
#include<stdio.h>

void insertionSort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int index = i-1;
        int key = arr[i];
        while(index>=0 && arr[index] > key)
        {
            arr[index+1] = arr[index];
            index--;
        }
        arr[index+1] = key;
    }
}
int main()
{
    int arr[] = {50,40,30,20,10};
    int n=5;
    insertionSort(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}