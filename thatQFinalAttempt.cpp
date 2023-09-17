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

int solve(int n, int m, vector<string> &maze)
{
    vvi dist(n, vi(m, 1e9));
    dist[0][0] = 0;
    pq<vi, vvi, greater<vi>> q;
    q.push({0, 0, 0});
    vi dx = {-1, 0, 0, 1};
    vi dy = {0, 1, -1, 0};
    while(!q.empty()){
        vi curr = q.top();
        q.pop();
        int x = curr[1];
        int y = curr[2];
        char c = maze[x][y];
        int free = 0;
        if (c == 'R')
        {
            free = 1;
        }
        else if (c == 'D')
        {
            free = 3;
        }
        else if (c == 'L')
        {
            free = 2;
        }
        for(int i=0;i<4;i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx<n && tx>=0 && ty<m && ty>=0){
                if(dist[tx][ty] > (i==free?0:1) + dist[x][y]){
                    dist[tx][ty] = (i==free?0:1) + dist[x][y];
                    q.push({dist[tx][ty], tx, ty});
                }
            }
        }
        return dist[n-1][m-1];
    }
}
