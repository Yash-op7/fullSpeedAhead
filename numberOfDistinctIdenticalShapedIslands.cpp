// 22:20

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

class Solution {
  public:

    vvi bfs(int x, int y, vvi &grid, vvb&vis){
        vvi ans;
        vis[x][y] = true;
        queue<vi>q;
        q.push({x, y});
        vi dx  ={ 1, -1, 0, 0};
        vi dy = {0, 0 ,1, -1};
        while(!q.empty()){
            vi front = q.front();
            q.pop();
            int x=  front[0];
            int y = front[1];
        }

    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vvi> shapes;
        vvb vis(n , vb(m, false));

        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    set.insert(bfs(i, j, grid, vis));
                }
            }
        }

    }
};