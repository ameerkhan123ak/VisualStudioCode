#include<stdio.h>
#include<limits.h>
int main()
{
  int arr[][9] = {  {1,7,2,5,4,9,6,8,3},
                    {6,4,5,8,7,3,2,1,9},
                    {3,8,9,2,6,1,7,4,5},
                    {4,9,6,3,2,7,8,5,1},
                    {8,1,5,4,5,6,9,7,2},
                    {2,5,7,1,9,8,4,3,6},
                    {9,6,4,7,1,5,4,3,6},
                    {7,3,1,6,8,2,5,9,4},
                    {5,2,8,9,3,4,1,6,7}};

  int rowsize=9,colsize=9;
  int x=0,y=rowsize-1;
  while(x<=y)
  {
    for(int i=0;i<rowsize;i++)
    {
      for(int j=0;j<colsize;j++)
      {
        if(arr[i][j]!=INT_MIN)
        {
          if(i==x || j==x || i==y || j==y)
          {
            printf("%d ",arr[i][j]);
            arr[i][j] = INT_MIN;
          }
          else if(arr[i][j]!=-1)
          printf("  ");
          }
      }
      printf("\n");
    }       
    x++;
    y--;
  }          
}