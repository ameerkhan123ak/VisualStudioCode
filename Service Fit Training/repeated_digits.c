/*
input: 11 15
There is the number 11 which has repeated digits but 12,13,14,15 have no repeated digits
output: 4
*/
#include<stdio.h>

int check_duplicates(int n)
{
    int arr[10] = {0};
    while(n)
    {
        int index = n%10;
        if(arr[index]>=1) return 0;
        arr[index]++;
        n/=10;
    }
    return 1;
}
int main()
{
    int start,end;
    scanf("%d %d",&start,&end);
    int count=0;
    for(int i=start;i<=end;i++)
    {
        if(check_duplicates(i)) 
        {
            printf("%d ",i);
            count++;
        }
    }
    printf("\n%d",count);
}