#include<stdio.h>
#include<limits.h>
int main()
{
  int arr[][7] = {{10,12,33,4},
                  {15,600,74,44},
                  {1,142,64,77},
                  {18,2,93,21}};

  int rowsize=sizeof(arr)/sizeof(arr[0]);
  int colsize=sizeof(arr)/sizeof(arr[0]); 
  int n=2;
  int sum=0;
  int max=0;
  int x=0,y=rowsize-1;
  while(x<=y)
  {
    sum=0;
    for(int i=0;i<rowsize;i++)
    {
      for(int j=0;j<colsize;j++)
      {
        if(arr[i][j]!=INT_MIN)
        {
          if(i==x || j==x || i==y || j==y)
          {
            sum += arr[i][j];
            arr[i][j] = INT_MIN;
          }
        }
      }
    }       
    if(sum>max) max = sum;
    x++;
    y--;
  }        
  printf("%d ",max);  
}