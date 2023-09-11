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

class Solution
{
public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int cnt1=0;
        int cnt0=0;
        vvb vis(n, vb(m, false));
        queue<vi> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    cnt1 ++;
                    if(i==0 || j==0 || i == n-1 || j==m-1){
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                }else{
                    cnt0++;
                }
            }
        }
        vi dx = {0, 0, 1, -1};
        vi dy = {1, -1, 0, 0};
        while(!q.empty()){
            vi front = q.front();
            int x = front[0];
            int y = front[1];
            cnt1--;
            for(int i=0;i<4;i++){
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(tx >= 0 && tx < n && ty >= 0 && ty <m && !vis[tx][ty] && grid[tx][ty] == 1){
                    q.push({tx, ty});
                    vis[tx][ty] = true;
                }
            }
        }
        return cnt1;
    }
};
