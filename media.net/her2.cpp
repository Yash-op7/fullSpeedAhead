#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int fn(int idx, int mask, int k, vector<int> &a, vector<vector<int>> &s, vector<vector<vector<int>>> &dp)
{
    int n = s.size();
    int p = s[0].size();
    if (k == 0 && mask == ((1 << p) - 1))
        return 0;
    if (idx == n)
        return -1e9;
    int &ret = dp[idx][mask][k];
    if (ret != -1)
        return ret;
    int stren = 0;
    if (k > 0)
    {
        stren = max(stren, (a[idx] + fn(idx + 1, mask, k - 1, a, s, dp)) % mod); // selecting as audience.
    }
    if (mask != (1 << p) - 1)
    {
        for (int i = 0; i < p; i++)
        {
            if (((mask>>i)&1) ==1)
                continue;
            stren = max(stren, (s[idx][i] + fn(idx + 1, (mask | (1 << i)), k, a, s, dp)) % mod);
            // selecting as player at position p.
        }
    }
    stren = max(stren, fn(idx+1, mask, k, a, s, dp));
    return ret = stren % mod;
}

int maxStrength(vector<int> &a, vector<vector<int>> &s, int k)
{
    int n = s.size();
    int p = s[0].size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>((1 <<(p)) + 1, vector<int>(k + 1, -1)));
    return (int)fn(0, 0, k, a, s, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> s(n, vector<int>(p));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> s[i][j];
        }
    }
    cout << maxStrength(a, s, k);
    return 0;
}