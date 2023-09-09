#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pq priority_queue
#define ll long long
#define MOD 1e9 + 7
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vvb vector<vb>

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};

void dfs(int x, int y, vector<string> &A, vvb &vis)
{
    if (vis[x][y])
    {
        return;
    }
    int n = A.size(), m = A[0].length();
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < n && tx >= 0 && ty >= 0 && ty < m && !vis[tx][ty] && A[tx][ty] == 'X')
        {
            dfs(tx, ty, A, vis);
        }
    }
}

int Solution::black(vector<string> &A)
{
    int n = A.size();
    int m = A[0].length();
    vvb vis(n, vb(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && A[i][j] == 'X')
            {
                ans++;
                dfs(i, j, A, vis);
            }
        }
    }
    return ans;

    // OOOXOOO
    // OOXXOXO
    // OXOOOXO
}
