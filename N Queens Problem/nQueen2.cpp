#include <iostream>
using namespace std;

const int N = 4;

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Checking left side
    for (i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }

    // Checking upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Checking lower left diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(int board[N][N], int col)
{
    if (col == N)
        return true;

    for (int row = 0; row < N; row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;

            if (solveNQueens(board, col + 1))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
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
