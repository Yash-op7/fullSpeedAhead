
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
//  6:18

void dfs(int src, vb &vis, vvi &adj, vi &temp){
    vis[src] = true;
    temp.push_back(src);
    for(auto next:adj[src]){
        if(!vis[next]){
            dfs(next, vis, adj, temp);
        }
    }
}
void dfs(int src, vb &vis, vvi &adj)
{
    vis[src] = true;
    for (auto next : adj[src])
    {
        if (!vis[next])
        {
            dfs(next, vis, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
    vb vis(v, false);
    vvi adj(v);
    for(const auto x:edges){
        adj[x[0]].push_back(x[1]);
    }

    vi temp;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i, vis, adj, temp);
        }
    }
    adj.clear();
    for(const auto x:edges){
        adj[x[1]].push_back(x[0]);
    }
    vis = vb(v, false);
    int ans = 0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i, vis, adj);
            ans++;
        }
    }
    return ans;
	
}