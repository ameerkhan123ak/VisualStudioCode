#include<stdio.h>
int checkData(int arr[])
{
    for(int i=0;i<9;i++)
    {
        if(arr[i]!=1) return 0;
    }
    return 1;
}
int checkSudoku(int arr[][9])
{
    int colsize=9;
    int colstart=0,colend=3;
    int rowstart=0,rowend=3;
    int l=9;
    while(l--)
    {
        int data[9] = {0};
        for(int i=rowstart;i<rowend;i++)
        {
            for(int j=colstart;j<colend;j++)
            {
                data[arr[i][j]-1] = 1;
            }
        }
        if(checkData(data)!=1) return 0; 
        colstart = colstart+3;
        colend = colend+3;
        if(colend>9) 
        {
            rowstart = rowstart+3;
            rowend = rowend + 3;
            colstart = 0;
            colend = 3;
        }
    }
    return 1;
}
int main()
{
    int arr[][9] = {{1,7,2,5,4,9,6,8,3},
                    {6,4,5,8,7,3,2,1,9},
                    {3,8,9,2,6,1,7,4,5},
                    {4,9,6,3,2,7,8,5,1},
                    {8,1,3,4,5,6,9,7,2},
                    {2,5,7,1,9,8,4,3,6},
                    {9,6,4,7,1,5,4,3,6},
                    {7,3,1,6,8,2,5,9,4},
                    {5,2,8,9,3,4,1,6,7}};
    int ans = checkSudoku(arr);
    if(ans) printf("YES");
    else printf("NO");
}