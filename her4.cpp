bool fn(int idx1, int idx2, string &a, vector<vector<vector<int>>> &dp, int limit)
{
    int n = dp.size() - 1;
    if (limit == 0)
        return dp[idx1][idx2][limit] = true;
    if (idx1 == n || idx1 == n)
        return dp[idx1][idx2][limit] = false;
    if (idx1 == idx2)
        return dp[idx1][idx2][limit] = false;
    if (dp[idx1][idx2][limit] != -1)
        return dp[idx1][idx2][limit];

    if (a[idx1] == a[idx2])
    {
        return dp[idx1][idx2][limit] = fn(idx1 + 1, idx2 + 1, a, dp, limit - 1); // if character matched, decrease limit.
    }
    return {
        dp[idx1][idx2][limit] = (fn(idx1 + 1, idx2, a, dp, limit) || fn(idx1, idx2 + 1, a, dp, limit))};
}

int Solution::anytwo(string a)
{
    int n = a.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3, -1)));
    // argument value 2 in the function is denoting, number of needed character to be matched.
    if (fn(0, 1, a, dp, 2))
        return 1;
    return 0;
}