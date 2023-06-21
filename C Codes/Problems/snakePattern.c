#include<stdio.h>
int main()
{
    int arr[][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    int flag=1;
    for(int i=0;i<3;i++)
    {
        if(flag)
        {
            for(int j=0;j<3;j++)
            {
                printf("%d ",arr[i][j]);
            }
        }
        else 
        {
            for(int j=2;j>=0;j--)
            {
                printf("%d ",arr[i][j]);
            }
        }
        flag=!flag;
        printf("\n");
    }                
}