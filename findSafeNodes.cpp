
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
    bool dfs(int src, vi adj[], vb&vis, vi &ans){
        if(vis[src]){
            return false;
        }
        if(adj[src].size() == 0){
            return true;
        }
        vis[src] = true;
        for(auto x:adj[src]){
            if (!dfs(x, adj, vis, ans)){
                return false;
            }
        }
        vis[src] = false;
        ans.push_back(src);
        return true;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vi ans;
        vb vis(V, false);
        for(int i=0;i<V;i++){
            if(adj[i].size() != 0){
                bool f = dfs(i, adj, vis, ans);
            }
            if(adj[i].size() == 0){
                ans.push_back(i);
            }
        }
        set<int> temp;
        for(int i=0;i<ans.size();i++){
            temp.insert(ans[i]);
        }
        ans.clear();
        for(auto x:temp){
            ans.push_back(x);
        }
        return ans;
    }
};