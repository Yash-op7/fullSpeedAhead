class Solution {
public:
int fn(int i, int j, const string &a, const string &b, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (i == 0 && j == 0)
        return dp[i][j] = 1;
    if (j == 0)
        return dp[i][j] = 0;
    if(i==0){
        if(b[j-1] == '*'){
            return fn(i, j-1, a, b, dp);
        }else{
            return 0;
        }

    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i - 1] == b[j - 1] || b[j - 1] == '?')
        return dp[i][j] = fn(i - 1, j - 1, a, b, dp);
    if (b[j - 1] == '*')
    {
        return dp[i][j] = (fn(i, j - 1, a, b, dp) || fn(i - 1, j, a, b, dp));
    }
    else
        return dp[i][j] = 0;
}
    bool isMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return fn(n, m, a, b, dp);
    }
};