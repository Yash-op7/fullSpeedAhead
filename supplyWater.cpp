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

void f(int curr, vvi adj[], vb &vis, vi &dist, vi &wells)
{
    for (const auto &neighbour : adj[curr])
    {
        int dest = neighbour[0];
        int pathCost = neighbour[1];
        if (!vis[dest])
        {
            int a = pathCost;
            int b = wells[dest];
            if (a < b && dist[dest] > a)
            {
                vis[dest] = true;
                dist[dest] = a;
                f(dest, adj, vis, dist, wells);
            }
            else
            {
                continue;
            }
        }
    }
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes)
{
    // Write your code here.
    vvi adj[n];
    for (const auto &x : pipes)
    {
        adj[x[0] - 1].push_back({x[1] - 1, x[2]});
        adj[x[1] - 1].push_back({x[0] - 1, x[2]});
    }
    vvi costs(n);
    for (int i = 0; i < n; i++)
    {
        costs[i] = {wells[i], i};
    }

    sort(all(costs));
    vi dist(n, INF);
    vb vis(n, false);

    for (const auto &x : costs)
    {
            dist[x[1]] = min(x[0], dist[x[1]]);
            vis = vb(n, false);
            vis[x[1]] = true;
            f(x[1], adj, vis, dist, wells);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += dist[i];
    }
    return ans;
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