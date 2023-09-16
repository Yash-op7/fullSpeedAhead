#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>

int f(int idx, int mask, vvi &cost)
{
    int n = cost.size();
    int m = cost[0].size();
    if (idx == cost.size())
    {
        if (mask + 1 == (1 << m))
        {
            return 0;
        }
        else
        {
            return 1e9;
        }
    }
    int ans = INT_MAX;
    int originalMask = mask;
    for (int i = 0; i < m; i++)
    {
        mask = (mask | (1 << i));
        ans = min(cost[idx][i] + f(idx + 1, mask, cost), ans);
        mask = originalMask;
    }
    return ans;
}

int connectTwoGroups(vector<vector<int>> &cost)
{
    //	Write your code here.
    int n = cost.size();
    int m = cost[0].size();
    if (n >= m)
    {
        return f(0, 0, cost);
    }
    else
    {
        vvi c(m, vi(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                c[j][i] = cost[i][j];
            }
        }
        return f(0, 0, c);
    }
}
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        vvi costs(n, vi(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> costs[i][j];
            }
        }
        cout << connectTwoGroups(costs) << endl;
    }
}