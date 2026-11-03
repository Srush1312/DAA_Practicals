#include <iostream>
using namespace std;

int board[8][8] = {0};

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1;
         i >= 0 && j < 8; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int row)
{
    if (row == 8)
        return true;

    // Try every column
    for (int col = 0; col < 8; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solve(row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int firstRow, firstCol;

    cout << "Enter first queen row and column (1-8): ";
    cin >> firstRow >> firstCol;

    // Validate input
    if (firstRow < 1 || firstRow > 8 ||
        firstCol < 1 || firstCol > 8)
    {
        cout << "Invalid position!";
        return 0;
    }

    firstRow--;
    firstCol--;

    board[firstRow][firstCol] = 1;

    if (solve(firstRow + 1))
    {
        cout << "\n8 Queens Solution:\n";

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists for this first queen position.";
    }
    return 0;
}
