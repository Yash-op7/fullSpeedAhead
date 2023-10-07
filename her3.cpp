#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
bool canGo(int x, int y, vector<string> &grid, vector<vector<int>> vis)
{
    int n = grid.size();
    int m = grid[0].size();
    if (x >= n || x < 0 || y >= m || y < 0 || vis[x][y] || grid[x][y] == 'O')
        return false;
    return true;
}
void fn(int x, int y, vector<string> &grid, vector<vector<int>> vis)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if (canGo(a, b, grid, vis))
        {
            fn(a, b, grid, vis);
        }
    }
}
int Solution::black(vector<string> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'X' && vis[i][j] == 0)
            {
                ans++;
                fn(i, j, grid, vis);
            }
        }
    }
    return ans;
}