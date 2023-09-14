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
    bool dfs(int src, int dest, vvi adj[], vb &vis, int &prevAns, int &currAns, vi &temp)
    {
        if (src == dest)
        {
            if (prevAns > currAns)
            {
                prevAns = currAns;
                return true;
            }
            return false;
        }
        vi currPath;
        for (const auto &x : adj[src])
        {
            if (!vis[x[0]])
            {
                vis[x[0]] = true;
                int curr = x[1] + currAns;
                vi temp1;
                if (dfs(x[0], dest, adj, vis, prevAns, curr, temp1))
                {
                    temp1.push_back(x[0] + 1);
                    currPath = temp1;
                }
                vis[x[0]] = false;
            }
        }
        vis[src] = false;
        if (currPath.empty())
        {
            return false;
        }
        // temp = currPath;
        temp.insert(temp.end(), currPath.begin(), currPath.end());
        return true;
    }

public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vvi adj[n];
        for (const auto &x : edges)
        {
            adj[x[0] - 1].push_back({x[1] - 1, x[2]});
            adj[x[1] - 1].push_back({x[0] - 1, x[2]});
        }
        vi ans;
        vb vis(n, false);
        int k = 0;
        vis[0] = true;
        int prevA = INT_MAX;
        bool kk = dfs(0, n - 1, adj, vis, prevA, k, ans);
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    int n, m;
    cin>>n>>m;
    vvi edges(m);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges[i] = {x, y, z};
    }
    vi ans = s.shortestPath(n, m, edges);
    for(auto x:ans){
        cout<<x<<endl;
    }
}