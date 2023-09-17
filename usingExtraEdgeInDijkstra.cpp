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

void dijkstra(int src, vvi adj[], vl &dist)
{
    dist[src] = 0;
    pq<vl, vvl, greater<vl>> q;
    q.push({dist[src], src});
    while (!q.empty())
    {
        vl top = q.top();
        q.pop();

        ll currDist = top[0];
        ll currNode = top[1];

        for (const auto &next : adj[currNode])
        {
            ll nextNode = next[0];
            ll distance = next[1];
            if (dist[nextNode] > distance + dist[currNode])
            {
                dist[nextNode] = distance + dist[currNode];
                q.push({dist[nextNode], nextNode});
            }
        }
    }
}

int solve(int A, vector<vector<int>> &B, int C, int D, vector<vector<int>> &E)
{
    vvi adj[A + 1];
    for (const auto &x : B)
    {
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }

    vl distSrc(A + 1, INT_MAX);
    vl distDest(A + 1, INT_MAX);

    dijkstra(C, adj, distSrc);
    dijkstra(D, adj, distDest);

    ll ans = INT_MAX;
    for (const auto &x : E)
    {
        int a = x[0];
        int b = x[1];
        ll wt = x[2];
        ans = min(
            distSrc[D],
            min(
                distSrc[a] + wt + distDest[b],
                distSrc[b] + wt + distDest[a]));
    }
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}
