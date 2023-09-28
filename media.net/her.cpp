#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

long long fn(int idx, int mask, int k, vector<int> &a, vector<vector<int>> &s, vector<vector<vector<long long>>> &dp)
{
    int n = s.size();
    int p = s[0].size();
    if (k == 0 && mask == ((1 << p) - 1))
        return 0;
    if (idx == n)
        return -1e9;
    // long long &ret = dp[idx][mask][k];
    // if (ret != -1)
    //     return ret;
    if(dp[idx][mask][k] != -1){
        return dp[idx][mask][k];
    }
    long long stren = 0;
    if (k > 0)
    {
        stren = max(stren, (a[idx] + fn(idx + 1, mask, k - 1, a, s, dp)) % mod); // selecting as audience.
    }
    if (mask != ((1 << p) - 1))
    {
        for (int i = 0; i < p; i++)
        {
            if (mask & (1 << p))
                continue;
            stren = max(stren, (s[idx][i] + fn(idx + 1, (mask | (1 << p)), k, a, s, dp)) % mod);
            // selecting as player at position p.
        }
    }
    return dp[idx][mask][k] = stren % mod;
}

int maxStrength(vector<int> &a, vector<vector<int>> &s, int k)
{
    int n = s.size();
    int p = s[0].size();
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>((1<<(p+1)), vector<long long>(k + 1, -1)));
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
    vector<vector<int>> s(n, vector<int>(p, 0));
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