
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

int f(int x, int y, vector<string> &maze, vvb &vis, vvi &t)
{
    int n = vis.size();
    int m = vis[0].size();
    if (x == n - 1 && y == m - 1)
    {
        return 0;
    }
    if (t[x][y] != -1)
    {
        return t[x][y];
    }
    char c = maze[x][y];
    int cost = 1e9;
    vi dx = {-1, 0, 0, 1};
    vi dy = {0, 1, -1, 0};
    //       U  R   L  D
    if (c == 'U')
    {
        int free = 0;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < n && tx >= 0 && ty < m && ty >= 0 && !vis[tx][ty])
            {
                vis[tx][ty] = true;
                cost = min(cost, (i == free ? 0 : 1) + f(tx, ty, maze, vis, t));
                vis[tx][ty] = false;
            }
        }
    }
    if (c == 'R')
    {
        int free = 1;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < n && tx >= 0 && ty < m && ty >= 0 && !vis[tx][ty])
            {
                vis[tx][ty] = true;
                cost = min(cost, (i == free ? 0 : 1) + f(tx, ty, maze, vis, t));
                vis[tx][ty] = false;
            }
        }
    }
    if (c == 'L')
    {
        int free = 2;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < n && tx >= 0 && ty < m && ty >= 0 && !vis[tx][ty])
            {
                vis[tx][ty] = true;
                cost = min(cost, (i == free ? 0 : 1) + f(tx, ty, maze, vis, t));
                vis[tx][ty] = false;
            }
        }
    }
    if (c == 'D')
    {
        int free = 3;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < n && tx >= 0 && ty < m && ty >= 0 && !vis[tx][ty])
            {
                vis[tx][ty] = true;
                cost = min(cost, (i == free ? 0 : 1) + f(tx, ty, maze, vis, t));
                vis[tx][ty] = false;
            }
        }
    }
    return t[x][y] = cost;
}

int solve(int A, int B, vector<string> &C)
{
    vvi t(A, vi(B, -1));
    vvb vis(A, vb(B, false));
    vis[0][0] = true;
    return f(0, 0, C, vis, t);
}
int main(){
    int n, m;

    cin>>n>>m;
    vector<string> c(n);
    getline(cin, c[0]);;
    for(int i=0;i<n;i++){
        getline(cin, c[i]);
    }
    cout<<solve(n, m, c)<<endl;
}