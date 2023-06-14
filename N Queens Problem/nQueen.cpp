#include <iostream>
using namespace std;

const int N = 8;

bool isSafe(int board[N][N], int row, int col)
{
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i)
    {
        if (board[i][col])
            return false;
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j])
            return false;
    }

    // Check if there is a queen in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueens(int board[N][N], int row)
{
    if (row == N)
        return true;

    for (int col = 0; col < N; ++col)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int board[N][N] = {0};

    if (solveNQueens(board, 0))
    {
        cout << "Solution:\n";
        printBoard(board);
    }
    else
    {
        cout << "No solution found!";
    }

    return 0;
}