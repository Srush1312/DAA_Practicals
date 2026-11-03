#include <iostream>
using namespace std;

int binomial(int n, int r)
{
    int dp[n + 1][r + 1];

    // Build the DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= r && j <= i; j++)
        {
            // Base cases
            if (j == 0 || j == i)
                dp[i][j] = 1;

            // Recursive relation
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][r];
}

int main()
{
    int n, r;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter r: ";
    cin >> r;

    cout << "Binomial Coefficient = "
         << binomial(n, r) << endl;

    return 0;
}
