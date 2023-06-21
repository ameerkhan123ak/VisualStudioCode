#include<stdio.h>
#include<math.h>
#define NOT_PRIME 1
#define PRIME 0

int arr[600000] = {0};
int main()
{
    int n=20;
    int index=0;
    int workIndex;
    arr[0] = arr[1] = NOT_PRIME;
    while(1)
    {
        while(arr[index] != 0) index++;
        if(index*index > n) break;
        for(workIndex = index*index; workIndex<=n; workIndex+=index) arr[workIndex] = NOT_PRIME;
        index++;
    }
    index=2;
    int count;
    int sum=0;
    for(count=2;count;count--)
    {
        while(arr[index] == 1) index++;
        printf("%d ",index);
        sum += index;
        index += 1;
    }
    if(arr[sum]==0) printf(" = %d",sum);
    printf("%d",sum);
}