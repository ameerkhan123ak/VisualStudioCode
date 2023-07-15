/*
In this algorithm, 

traverse from left and compare adjacent elements and the higher one is placed at right side. 
In this way, the largest element is moved to the rightmost end at first. 
This process is then continued to find the second largest and place it and so on until the data is sorted.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include<stdio.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
}
int main()
{
    int arr[] = {50,40,30,20,10};
    int n=5;
    bubbleSort(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}