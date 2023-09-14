
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
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        vb vis(N, false);
        vi dist(N, 1e9);
        vvi adj(N);
        for(const auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        queue<int> q;
        q.push(src);
        vis[src] = true;
        q.push(-1);
        int spread = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(top == -1){
                if(q.empty()){
                    break;
                }else{
                    spread++;
                    q.push(-1);
                }
            }
            else{
                dist[top] = spread;
                for(const auto &x:adj[top]){
                    if(!vis[x]){
                        vis[x] = true;
                        q.push(x);
                    }
                }
            }
        }
        return dist;
    }
};
