#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>

vi dx = {0, 0, -1, 1};
vi dy = {1, -1, 0, 0};

int f(int x, int y, int b, vector<vector<char>> &maze, vector<vb> &vis)
{
    if (maze[x][y] == 'G')
    {
        return 0;
    }
    int n = vis.size();
    int m = vis[0].size();
    int ans = 1e9;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < n && tx >= 0 && ty >= 0 && ty < m && !vis[tx][ty])
        {
            char c = maze[tx][ty];
            if (c == '#')
            {
                if (b > 0)
                {
                    vis[tx][ty] = true;
                    ans = min(ans, 1 + f(tx, ty, b - 1, maze, vis));
                    vis[tx][ty] = false;
                }
            }
            else
            {
                vis[tx][ty] = true;
                ans = min(ans, 1 + f(tx, ty, b, maze, vis));
                vis[tx][ty] = false;
            }
        }
    }
    return ans;
}

int main()
{
    int n, m, b;
    cin >> n >> m >> b;
    vector<vector<char>> maze(n, vector<char>(m, '.'));
    int x = -1;
    int y = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
            {
                x = i;
                y = j;
            }
        }
    }
    vector<vb> vis(n, vb(m, false));
    vis[x][y] = true;
    cout << f(x, y, b, maze, vis) << '\n';
}