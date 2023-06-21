#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool validSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> rowSet[9],colSet[9],squareSet[9];

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                char val = board[i][j];
                if(val != '.')
                {
                    if(rowSet[i].count(val) || colSet[j].count(val) || squareSet[3*(i/3)+j/3].count(val))
                    {
                        return false;
                    }
                    rowSet[i].insert(val);
                    colSet[j].insert(val);
                    squareSet[(i/3)*3+j/3].insert(val);
                }
            }
        }
        return true;
    }
};
int main()
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                   {'6','.','.','1','9','5','.','.','.'},
                                   {'.','9','8','.','.','.','.','6','.'},
                                   {'8','.','.','.','6','.','.','.','3'},
                                   {'4','.','.','8','.','3','.','.','1'},
                                   {'7','.','.','.','2','.','.','.','6'},
                                   {'.','6','.','.','.','.','2','8','.'},
                                   {'.','.','.','4','1','9','.','.','5'},
                                   {'.','.','.','.','8','.','.','7','9'}};

    Solution s;
    if(s.validSudoku(board)) cout<<"TRUE";
    else cout<<"FALSE";  
}