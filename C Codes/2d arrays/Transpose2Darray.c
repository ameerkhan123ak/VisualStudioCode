#include<stdio.h>
int main()
{
	int arr[3][3] = {{4,5,2},
	                 {1,7,6},
					 {8,9,3}};
	int row = sizeof(arr)/sizeof(arr[0]);
	int col = sizeof(arr[0])/sizeof(arr[0][0]);
	int temp[row][col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			temp[i][j] = arr[j][i];
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d ",temp[i][j]);
		}
		printf("\n");
	}
}