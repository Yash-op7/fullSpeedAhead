/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
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
    int findCheapestPrice(int n, vector<vector<int>> &flights,
                          int src, int dst, int k)
    {
        vvi adj[n];
        for (const auto x : flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        pq<vi, vvi, greater<vi>>q;
        vi dist(n, 1e9);
        dist[src] = 0;
        q.push({0, dist[src], src});

        while(!q.empty()){
            vi top = q.top();
            q.pop();
            int curr = top[2];
            if(curr =dst){
                return dist[dst];
            }
            if(top[0] == k){
                return -1;
            }
            int currk = top[0];
            for(const auto next:adj[curr]){
                if(dist[next[0]] > dist[curr] + next[1]){
                    dist[next[0]] = dist[curr] + next[1];
                    q.push({top[0] + 1, dist[next[0]], next[0]});
                }
            }
        }
        return -1;
    }
};
// @lc code=end
