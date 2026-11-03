#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            // No items or no capacity
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            // Current item can fit
            else if (wt[i - 1] <= w)
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );

            // Current item cannot fit
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[n], val[n];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int result = knapsack(W, wt, val, n);

    cout << "Maximum value = " << result << endl;

    return 0;
}
