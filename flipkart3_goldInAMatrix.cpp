#include <bits/stdc++.h>

int maxProfit(vector<int> &prices, int n)
{

    n = prices.size();

    vector<int> dp(n, 0);

    int mx = prices[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {

        if (prices[i] > mx)
        {

            mx = prices[i];
        }

        dp[i] = max(dp[i + 1], mx - prices[i]);
    }

    int mn = prices[0];

    for (int i = 1; i < n; i++)
    {

        if (mn > prices[i])
        {

            mn = prices[i];
        }

        dp[i] = max(dp[i - 1], dp[i] + (prices[i] - mn));
    }

    return dp[n - 1];
}
