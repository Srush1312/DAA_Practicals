#include <iostream>
using namespace std;

int board[20][20];
int n;

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
         i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int row)
{
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            // Place queen
            board[row][col] = 1;

            // Place queen in next row
            if (solve(row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Enter value of n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    // First queen is already placed
    int firstRow, firstCol;

    cout << "Enter row and column of first queen: ";
    cin >> firstRow >> firstCol;

    // Convert to 0-based indexing
    firstRow--;
    firstCol--;

    board[firstRow][firstCol] = 1;

    if (solve(firstRow + 1))
    {
        cout << "\nN-Queens Solution:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}
