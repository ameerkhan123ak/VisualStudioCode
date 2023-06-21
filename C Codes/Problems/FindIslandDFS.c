// Given a binary 2D matrix, find the number of islands. 
// A group of connected 1s forms an island. 
// For example, the below matrix contains 5 islands.
// Input: mat[][] =          {{1, 1, 0, 0, 0},
//                            {0, 1, 0, 0, 1},
//                            {1, 0, 0, 1, 1},
//                            {0, 0, 0, 0, 0},
//                            {1, 0, 1, 0, 0}}
// Output: 5
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define ROW 5
#define COL 5

int isSafe(int arr[][COL],int row,int col,bool visited[][COL])
{
    return (row>=0) && (row<ROW) && (col>=0) && (col<COL) && (arr[row][col] && !visited[row][col]);
}
void DepthFirstSearch(int arr[][COL],int row,int col,bool visited[][COL])
{
    static int rowNumber[] = {-1,-1,-1,0,0,1,1,1};
    static int colNumber[] = {-1,0,1,-1,1,-1,0,1};

    visited[row][col] = true;
    for(int k=0;k<8;k++)
    {
        if(isSafe(arr,row+rowNumber[k],col+colNumber[k],visited))
        {
            DepthFirstSearch(arr,row+rowNumber[k],col+colNumber[k],visited);
        }
    }
}
int countIslands(int arr[][5])
{
    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));
    int count=0;
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(arr[i][j] && !visited[i][j])
            {
                DepthFirstSearch(arr,i,j,visited);
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int arr[ROW][COL] ={{1,1,0,0,0},
                        {0,1,0,0,1},
                        {1,0,0,1,1},
                        {0,0,0,0,0},
                        {1,0,1,0,1}};
    printf("Number of islands: %d",countIslands(arr));
    return 0;                
}