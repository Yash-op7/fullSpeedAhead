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

bool f(int src, int dest, vvi adj[], int parent, int &ans, map<vi, int> &t)
{
    if (src == dest)
    {
        return true;
    }
    if (t.find({src, dest}) != t.end())
    {
        ans = t[{src, dest}];
        return true;
    }
    if (t.find({dest, src}) != t.end())
    {
        ans = t[{dest, src}];
        return true;
    }
    int unvisNeighbours = 0;
    for (const auto x : adj[src])
    {
        if (x[0] != parent)
        {
            if (f(x[0], dest, adj, src, ans, t))
            {
                ans = max(ans, x[1]);
                if (ans <= x[1])
                {
                    t[{src, dest}] = x[1];
                }
                unvisNeighbours++;
            }
        }
    }
    if (unvisNeighbours == 0)
    {
        return false;
    }
    return true;
}

vector<int> Solution::solve(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int n = A.size() + 1;
    vvi adj[n + 1];
    for (const auto edge : A)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    vi ans(B.size(), 0);
    int q = B.size();
    int ans1 = INT_MIN;
    map<vi, int> t;
    for (int i = 0; i < q; i++)
    {
        bool k = f(B[i][0], B[i][1], adj, -1, ans1, t);
        ans[i] = ans1;
        ans1 = INT_MIN;
    }
    return ans;
}
