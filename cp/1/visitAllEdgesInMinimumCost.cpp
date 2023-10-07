#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int n;
    int tot_sum;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> dist;
    Graph(int _n, vector<vector<int>> &roads)
    {
        n = _n;
        tot_sum = 0;
        dist.resize(n, vector<int>(n, 1e9));
        adj.resize(n);
        for (auto rd : roads)
        {
            adj[rd[0] - 1].push_back({rd[1] - 1, rd[2]});
            adj[rd[1] - 1].push_back({rd[0] - 1, rd[2]});
            tot_sum += rd[2];
            dist[rd[0] - 1][rd[1] - 1] = rd[2];
            dist[rd[1] - 1][rd[0] - 1] = rd[2];
        }
    }
    void dfs(int node, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
            if (vis[it.first] == 0)
                dfs(it.first, vis);
    }
    bool isConnected()
    {
        vector<int> vis(n, 0);
        dfs(0, vis);
        for (int i = 0; i < n; i++)
            if (vis[i] == 0)
                return 0;
        return 1;
    }
    bool isEulerianPossible()
    {
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() % 2)
                return 0;
        }
        return 1;
    }
    void findShortestPath()
    {
        for (int p = 0; p < n; p++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][p] + dist[p][j]);
                }
            }
        }
    }

    int extraHelper(vector<int> &unUsed)
    {
        if (unUsed.size() == 2)
        {
            return dist[unUsed[0]][unUsed[1]];
        }
        int src = unUsed.back();
        unUsed.pop_back();
        int ans = INT_MAX;
        for (int i = 0; i < unUsed.size(); i++)
        {
            vector<int> newUnused = unUsed;
            newUnused.erase(newUnused.begin() + i);
            int tmp = dist[src][unUsed[i]];
            tmp += extraHelper(newUnused);
            ans = min(ans, tmp);
        }
        return ans;
    }
    int extraTime()
    {
        vector<int> unUsed;
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() % 2)
                unUsed.push_back(i);
        }
        return extraHelper(unUsed);
    }
};

int minTravelTime(int n, vector<vector<int>> &roads)
{
    // Write your code here
    Graph g(n, roads);
    if (!g.isConnected())
        return -1;
    if (g.isEulerianPossible())
        return g.tot_sum;
    g.findShortestPath();
    return g.tot_sum + g.extraTime();
}
