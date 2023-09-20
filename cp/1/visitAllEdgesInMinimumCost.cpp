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

ll f(int src, int k, vvi adj[], vvb &vis, int start){
    if(k==0 && src == start){
        return 0;
    }
    if( k== 0 ){
        return 1e9;
    }
    ll ans= 0;
    for(vi x:adj[src]){
        int next = x[0];
        int time = x[1];
        if(!vis[next][src]){
            ans += time;
            ll temp = f(next, k-1, adj, vis, start);
            if(temp >= 1e9){
                ans+=time;
                vis[src][next] = true;
                vis[next][src] = true;
                
            }
        }
    }
}

int minTravelTime(int n, vector<vector<int>> &roads)
{
    // Write your code here
    int k = roads.size();
    vvi adj[n+1];
    for(auto x:roads){
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }
    ll ans = INT_MAX;
    for(int i=1;i<=n;i++){
        vvb vis(n+1, vb(n+1, false));
        ans = min(ans, f(i, k, adj, vis, i));
    }
    return ans;
}