
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

int minCostToDestination(int **a, int n, int m, int x, int y)
{
    //  Write your code here
    vvi dist(n, vi(m, 1e9));
    dist[0][0] = 0;
    pq<vi, vvi, greater<vi>> q;
    q.push({dist[0][0], 0, 0});
    int ans = 1e9;
    vi dx = {0, 0, 1, -1};
    vi dy = {1, -1, 0, 0};
    while (!q.empty())
    {
        vi curr = q.top();
        q.pop();
        int currDist = curr[0];
        int i = curr[0];
        int j = curr[1];
        if (i == x && y == j)
        {
            return dist[i][j];
        }
        for (int k = 0; k < 4; k++)
        {
            int tx = i + dx[k];
            int ty = j + dy[k];
            if (tx >= 0 && tx < n && ty < m && ty >= 0 && a[tx][ty] == 1)
            {
                if (k < 2)
                {
                    if (dist[tx][ty] > dist[i][j])
                    {
                        dist[tx][ty] = dist[i][j];
                        q.push({dist[tx][ty], tx, ty});
                    }
                }
                else
                {
                    if (dist[tx][ty] > 1 + dist[i][j])
                    {
                        dist[tx][ty] = 1 + dist[i][j];
                        q.push({dist[tx][ty], tx, ty});
                    }
                }
            }
        }
    }

    if (ans >= 1e9)
    {
        return -1;
    }
    return ans;
}
