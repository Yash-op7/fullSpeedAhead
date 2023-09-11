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
    bool dfs(int src, vvi &adj, vb&vis, vb&vis2){
        vis2[src] = true;
        if(vis[src]){
            return true;
        }
        vis[src] = true;
        for(auto x:adj[src]){
            if(dfs(x, adj, vis, vis2)){
                return true;
            }
        }
        vis[src] = false;
        return false;
    }

public:
	bool isPossible(int N,int P, vector<pair<int, int> >& p) {
	    // Code here
        vvi adj(N);
        for(auto x:p){
            adj[x.second].push_back(x.first);
        }
        vb vis2(N, false);
        for(int i=0;i<N;i++){
            if(!vis2[i]){
                vb vis(N, false);
                if (dfs(i, adj, vis, vis2))
                {
                    return false;
                }
            }
        }
        return true;
	}
};