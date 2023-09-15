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
    void dfs(int src, vvi adj[], vi &dist, vb&vis){
        vis[src] = true;
        for(const auto &x:adj[src]){
            int from = src;
            int to = x[0];
            int wt = x[1];
            if(dist[to] > dist[src] + wt){
                dist[to] = dist[src] + wt;
                if(!vis[to]){
                    dfs(to, adj, dist, vis);
                }
            }
        }
        vis[src] = false;
    }
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        vi dist(N, 1e9);
        dist[0] = 0;
        vi indegree(N, 0);
        vvi adj[N];
        for(const auto &x:edges){
            adj[x[0]].push_back({x[1], x[2]});
            indegree[x[1]]++;
        }

        int src = 0;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto x:adj[curr]){
                int dest = x[0];
                int dis = x[1];
                if(dist[curr] + dis < dist[dest]){
                    dist[dest] = dist[curr] + dis;
                }
                indegree[dest]--;
                if(indegree[dest] == 0){
                    q.push(dest);
                }
            }
        }

        for(auto &x:dist){
            if(x == 1e9){
                x = -1;
            }
        }
        return dist;
    }
};