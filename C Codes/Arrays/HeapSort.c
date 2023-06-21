#include<stdio.h>
void swap(int arr[],int index1,int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
void maxHeapify(int arr[],int parentIndex,int scope)
{
    int leftIndex = parentIndex*2 + 1;
    int rightIndex = leftIndex + 1;
    if(rightIndex <= scope)
    {
        if(arr[leftIndex] > arr[parentIndex] && arr[leftIndex] > arr[rightIndex])
        {
            swap(arr,parentIndex,leftIndex);
            maxHeapify(arr,leftIndex,scope);
        }
        else if(arr[rightIndex] > arr[parentIndex])
        {
            swap(arr,parentIndex,rightIndex);
            maxHeapify(arr,rightIndex,scope);
        }
    }
    else if(leftIndex == scope)
    {
        if(arr[leftIndex] > arr[parentIndex])
        swap(arr,parentIndex,leftIndex);
    }
}
int main()
{ 
    int arr[] = {7,6,5,4,3,2,1};
    int no_of_elements = sizeof(arr)/sizeof(arr[0]);
    int scope;
    for(scope=no_of_elements-1;scope>0;scope--)
    {
        maxHeapify(arr,0,scope);
        swap(arr,0,scope);
    }
    for(int i=0;i<no_of_elements;i++) printf("%d ",arr[i]);
}