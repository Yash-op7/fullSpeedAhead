#include <bits/stdc++.h>

int modifiedLudo(vector<vector<int>> &edges, int n)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 && (i + j <= n); j++)
        {
            adj[i].push_back({i + j, 1}); // adj[i+j].push_back({i,1});        }    }    for(auto &x:edges)    {        int a=x[0],b=x[1];        adj[a].push_back({b,0});        // adj[b].push_back({a,0});    }

            vector<int> dist(n + 1, INT_MAX);
            dist[1] = 0;
            priority_queue<pair<int, int>> pq;
            pq.push({0, 1});
            while (!pq.empty())
            {
                pair<int, int> temp = pq.top();
                pq.pop();
                int a = -1 * temp.first, b = temp.second;
                for (auto &x : adj[b])
                {
                    if (dist[b] + x.second < dist[x.first])
                    {
                        dist[x.first] = dist[b] + x.second;
                        pq.push({-1 * dist[x.first], x.first});
                    }
                }
            }

            return dist[n];
        }