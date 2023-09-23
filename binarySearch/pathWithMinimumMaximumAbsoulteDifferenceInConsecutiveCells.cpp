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

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        pq<vi, vvi, greater<vi>>q;
        q.push({0, 0, 0});          // curr {max, x, y}
        int n = heights.size();
        int m = heights[0].size();
        vvb vis(n, vb(m, false));
        vvi dist(n, vi(m, 1e9));
        vis[0][0] = true;
        dist[0][0] = 0;
        vi dx = {0, 0, 1, -1};
        vi dy = {1, -1, 0, 0};
        while(!q.empty()){
            vi curr = q.top();
            int x = curr[1];
            int y = curr[2];
            int diff = curr[0];

            if(x == n-1 && y == m-1){
                return diff;
            }

            for(int i=0;i<4;i++){
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(tx >=0 && tx < n && ty >=0 && ty < m){
                    int newEffort = max(diff, abs(heights[tx][ty] - heights[x][y]));
                    if(dist[tx][ty] > newEffort){
                        // discovered a better path
                        dist[tx][ty] = newEffort;
                        q.push({newEffort, tx, ty});
                    }
                }
            }
        }
        return -1;
    }
};