#include<stdio.h>
#define SIZE 3
int main()
{
  int arr1[][SIZE] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}};
  int arr2[][SIZE] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}};
  int ans[3][3];       
  for(int row=0;row<SIZE;row++)
  {
    for(int col=0;col<SIZE;col++)
    {
      int sum=0;
      for(int i=0;i<SIZE;i++)
      {
        sum += arr1[row][i] * arr2[i][col];
      }
      ans[row][col] = sum;
    }
  }
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      printf("%3d ",ans[i][j]);
    }
    printf("\n");
  }
}
/*
00 x 00   00 x 01  00 x 02
01 x 10   01 x 11  01 x 12
02 x 20   02 x 21  02 x 22
 
10 x 00   10 x 01  10 x 02
11 x 10   11 x 11  11 x 12
12 x 20   12 x 21  12 x 22
 
20 x 00   20 x 01  20 x 02
21 x 10   21 x 11  21 x 12
22 x 20   22 x 21  22 x 22
*/