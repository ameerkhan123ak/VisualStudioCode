#include<stdio.h>
#define rowsize 3
#define colsize 3
int main()
{
    int matrix[][3] = {{1,2,3},
                       {4,5,6},
                       {7,8,9}};

    int row=0,col=-1;
    
    for(int i=0;i<rowsize;i++)
    {
        for(int j=colsize-1;j>=0;j--)
        {
            matrix[row][++col] = matrix[j][i];
        }
        row++;
        col=-1;
    }
    for(int i=0;i<rowsize;i++)
    {
        for(int j=0;j<colsize;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=2;j>=0;j--)
    //     {
    //         printf("%d ",arr[j][i]);
    //     }
    //     printf("\n");
    // }               
}