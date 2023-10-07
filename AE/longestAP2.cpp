int Solution::solve(const vector<int> &a)
{
    unordered_map<int, int> mp;
    int n = a.size();
    if (n <= 2)
        return n;
    int dp[1001][1001];
    int maxi = 2;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dp[i][j] = 2;
            int need = 2 * a[i] - a[j];
            if (mp.find(need) != mp.end())
            {
                dp[i][j] = max(dp[i][j], 1 + dp[mp[need]][i]);
                maxi = max(maxi, dp[i][j]);
            }
        }
        mp[a[i]] = i;
    }
    return maxi;
}
