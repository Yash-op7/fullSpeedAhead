#include <bits/stdc++.h>
using namespace std;
int nodesWithinKDistance(vector<vector<int>> &edges, int v, vector<int> &marked, int m, int k)
{
    vector<vector<int>> adjList(v + 1);
    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<vector<int>> distancesFromMarked(m);
    for (int i = 0; i < m; i++)
    {
        vector<int> distance(v + 1, -1);
        int src = marked[i];
        queue<int> q;
        q.push(src);
        distance[src] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int neighbor : adjList[node])
            {
                if (distance[neighbor] == -1)
                {
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        distancesFromMarked[i] = distance;
    }
    vector<bool> withinK(v + 1, true);
    for (int i = 1; i <= v; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (distancesFromMarked[j][i] > k)
            {
                withinK[i] = false;
                break;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= v; i++)
    {
        if (withinK[i])
        {
            count++;
        }
    }
    return count;
}