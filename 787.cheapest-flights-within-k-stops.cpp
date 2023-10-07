#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
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
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> adj[n];
        for (const auto x : flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        queue<vector<int>> q;
        q.push({src, 0});
        q.push({});
        int radius = 0;
        int ans = INT_MAX;
        vector<int> dist(n, 1e9);
        while (!q.empty())
        {
            vector<int> front = q.front();
            q.pop();
            if (front.empty())
            {
                if (q.empty())
                {
                    break;
                }
                else
                {
                    q.push({});
                    if (radius == k + 1)
                    {
                        break;
                    }
                    radius += 1;
                    continue;
                }
            }
            int currNode = front[0];
            int currDist = front[1];
            if (currNode == dst)
            {
                ans = min(currDist, ans);
                continue;
            }
            for (const auto x : adj[currNode])
            {
                if (dist[x[0]] > currDist + dist[currNode])
                {
                    dist[x[0]] = currDist + dist[currNode];
                    q.push({x[0], currDist + x[1]});
                }
            }
        }
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};