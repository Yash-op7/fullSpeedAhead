/*
    Time Complexity : O(N^3)
    Space Complexity : O(N^2)

    Where, N is the size of the array.
*/
#include <bits/stdc++.h>
using namespace std;

int greedyJeweller(int n, vector<vector<int>> &mat)
{

    int m = (n - 1) * 2;
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Base case.
    dp[0][0] = mat[0][0];
    for (int i = 1; i <= m; i++)
    {

        // New dp array to store the values at current position.
        vector<vector<int>> dpNew(n, vector<int>(n, -1));
        for (int j = n - 1; j >= 0; j--)
        {
            for (int k = n - 1; k >= 0; k--)
            {

                // Check for valid path.
                if (i - j < 0 || i - j >= n || i - k < 0 || i - k >= n || mat[j][i - j] == -1 || mat[k][i - k] == -1)
                {
                    continue;
                }

                dpNew[j][k] = dp[j][k];
                if (j > 0)
                {
                    dpNew[j][k] = max(dpNew[j][k], dp[j - 1][k]);
                }

                if (k > 0)
                {
                    dpNew[j][k] = max(dpNew[j][k], dp[j][k - 1]);
                }

                if (j > 0 && k > 0)
                {
                    dpNew[j][k] = max(dpNew[j][k], dp[j - 1][k - 1]);
                }

                if (dpNew[j][k] < 0)
                {
                    continue;
                }

                // Check if gold is present at current position for first path.
                dpNew[j][k] += mat[j][i - j];

                // Check if gold is present at current position for second path.
                if (j != k)
                {
                    dpNew[j][k] += mat[k][i - k];
                }
            }
        }

        // Update dp array.
        dp = dpNew;
    }
    return max(0, dp[n - 1][n - 1]);
}