#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

void flip(vvi &a)
{
    int n = a.size();
    vvi b(n, vi(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[n - i - 1][n - j - 1] = a[i][j];
        }
    }
    a = b;
}

int f(int x, int y, bool coming, vvi &a, vvvi &t)
{
    int n = a.size();
    if (coming && x == 0 && y == 0)
    {
        return 0;
    }
    int bit;
    if (coming)
    {
        bit = 1;
    }
    else
    {
        bit = 0;
    }
    if (!coming && x == n - 1 && y == n - 1)
    {
        t[x][y][bit] = f(x, y, !coming, a, t);
        return t[x][y][1 - bit] = t[x][y][bit];
    }
    if (t[x][y][bit] != -1)
    {
        return t[x][y][bit];
    }
    if (!coming)
    {
        int d = -1e5;
        int r = -1e5;
        int temp1 = -2;
        int temp2 = -2;
        if (x + 1 < n && a[x + 1][y] != -1)
        {
            temp1 = a[x + 1][y];
            a[x + 1][y] = 0;
            d = temp1 + f(x + 1, y, coming, a, t);
            a[x + 1][y] = temp1;
        }
        if (y + 1 < n && a[x][y + 1] != -1)
        {
            temp2 = a[x][y + 1];
            a[x][y + 1] = 0;
            r = temp2 + f(x, y + 1, coming, a, t);
            a[x][y + 1] = temp2;
        }
        if (max(d, r) < 0)
        {
            // a[x+1][y] = temp1;
            // a[x][y+1] = temp2;
            return t[x][y][bit] = -1e5;
        }
        return t[x][y][bit] = max(d, r);
    }
    else
    {
        // on the return journey
        int u = 0;
        int l = 0;
        int temp1 = -2;
        int temp2 = -2;
        if (x - 1 >= 0)
        {
            temp1 = a[x - 1][y];
            a[x - 1][y] = 0;
            u = temp1 + f(x - 1, y, coming, a, t);
            a[x - 1][y] = temp1;
        }
        if (y - 1 >= 0)
        {
            temp2 = a[x][y - 1];
            a[x][y - 1] = 0;
            l = temp2 + f(x, y - 1, coming, a, t);
            a[x][y - 1] = temp2;
        }
        return t[x][y][bit] = max(u, l);
    }
}

int greedyJeweller(int n, vector<vector<int>> &a)
{
    // Write your code here.
    if (a[0][0] == -1)
    {
        return 0;
    }
    int temp = a[0][0];
    a[0][0] = 0;
    vvvi t(n, vvi(n, vi(2, -1)));
    int ans = temp + f(0, 0, false, a, t);
    if (ans < 0)
    {
        return 0;
    }
    return ans;
}
