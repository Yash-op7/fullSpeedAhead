#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
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

    void dfs(int src, vvi&adj, vb&vis, vi &fin){
        vis[src] = true;
        for(const int &x:adj[src]){
            if(!vis[x]){
                dfs(x, adj, vis, fin);
            }
        }
        fin.push_back(src);
    }

    void dfs(int src, vvi &adj, vb &vis){
        vis[src] = true;
        for(const auto&x:adj[src]){
            if(!vis[x]){
                dfs(x, adj, vis);
            }
        }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vb vis(V, false);
        vi finishingTimes;
        dfs(0, adj, vis, finishingTimes);
        vis = vb(V, false);
        // reverse(finishingTimes.begin(), finishingTimes.end());
        vvi adjRev(V);
        for(int i=0;i<V;i++){
            for(const int &x:adj[i]){
                adjRev[x].push_back(i);
            }
        }
        int ans = 0;
        for(int i=0;i<V;i++){
            int curr = finishingTimes.back();
            finishingTimes.pop_back();
            if(!vis[curr]){
                dfs(curr, adjRev, vis);
                ans++;
            }
        }
        return ans;
    }
};