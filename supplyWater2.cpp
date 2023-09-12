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
const ll INF = 1e6;
const int MOD = 1e9 + 7;

// const int nmax = 101;
// int parent[nmax];
// int sz[nmax];
// int dist[nmax];

// void makeSet(int x){
//     parent[x] = x;
//     sz[x] = 1;
//     dist[x] = INF;
// }

// int find(int x){
//     if(x == parent[x]){
//         return x;
//     }
//     return parent[x] = find(parent[x]);
// }

int f(int src, bool hasWater, vvi adj[], vb &vis, vi &wells, vb &vis2) {
    vis2[src] = true;
    if(!hasWater){
        int place = wells[src];
        for(const auto &x:adj[src]){
            if(!vis[x[0]]){
                vis[x[0]] = true;
                place += f(x[0], true, adj, vis, wells ,vis2);
                vis[x[0]] = false;
            }
        }
        int dontPlace = INT_MAX;
        for(const auto &x:adj[src]){
            int temp = 0;
            if(!vis[x[0]]){
                temp += f(x[0], false, adj, vis, wells, vis2);
                for(const auto &y:adj[src]){
                    if(!vis[y[0]] && x[0] != y[0]){
                        temp+=f(y[0], true, adj, vis, wells, vis2 );
                    }
                }
            }
            dontPlace = min(dontPlace, temp);
        }
        if (dontPlace == INT_MAX)
        {
            return place;
        }
        return min(place, dontPlace);
    }else{
        int connect = 0;
        int disconnect= 0 ;
        
    }
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes)
{

    vb vis(n, false);
    vvi adj[n];
    for (const auto &x : pipes)
    {
        adj[x[0] - 1].push_back({x[1] - 1, x[2]});
        adj[x[1] - 1].push_back({x[0] - 1, x[2]});
    }
    int ans = 0;
    vb vis2(n ,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans += f(i, false, adj, vis, wells, vis2);
        }
    }
}


int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        vi wells(n);
        rep(i, 0, n) cin >> wells[i];
        vvi edges(k);
        rep(i, 0, k)
        {
            int x, y, z;
            ;
            cin >> x >> y >> z;
            edges[i] = {x, y, z};
        }
        cout << supplyWater(n, k, wells, edges) << '\n';
    }
}