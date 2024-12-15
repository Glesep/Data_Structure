#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col ||
            board[i] - i == col - row ||
            board[i] + i == col + row)
        {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int> &board, int &count)
{
    if (row == n)
    {
        count++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            solveNQueens(n, row + 1, board, count);
        }
    }
}

int countNQueensSolutions(int n)
{
    vector<int> board(n, 0);
    int count = 0;
    solveNQueens(n, 0, board, count);
    return count;
}

int main()
{
    for (int n = 1; n <= 15; n++)
    {
        int solutions = countNQueensSolutions(n);
        cout << solutions << " ";
    }
    cout << endl;
    return 0;
}
