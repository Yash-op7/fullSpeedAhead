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

int f(int src, bool hasSupply, vi &wells, vvi&adj, vb&vis){
    int place = wells[src-1];

}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
  	// Write your code here.
    vb vis(n+1, false);
    vvi adj(n+1);
    for(const auto&x:pipes){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    ll ans= 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans+= f(i,false,  wells, adj, vis);
        }
    }
}