
#include <bits/stdc++.h>

int modifiedLudo(vector<vector<int>> &connections, int n)
{
    // Write your code here

    vector<vector<int>> adj(n + 1);
    for (const auto x : connections)
    {
        adj[x[0]].push_back(x[1]);
    }
    queue<int> q;
    vector<bool> vis(n + 1, false);

    q.push(1);
    vis[1] = true;
    if (!adj[1].empty())
    {
        for (const int x : adj[1])
        {
            q.push(x);
            if (x == n)
            {
                return 0;
            }
            vis[x] = true;
        }
    }
    int moves = 0;
    q.push(-1);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == -1)
        {
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(-1);
                moves++;
            }
        }
        else
        {
            if (curr == n)
            {
                return moves;
            }
            if (!adj[curr].empty())
            {
                for (auto x : adj[curr])
                {
                    if (!vis[x])
                    {
                        if(x == n){
                            return moves;
                        }
                        vis[x] = true;
                        q.push(x);
                    }
                }
            }
            for (int i = 1; i <= 6; i++)
            {
                if (!vis[curr + i])
                {
                    if(curr+i == n){
                        return moves;
                    }
                    vis[curr + i] = true;
                    q.push(curr + i);
                }
            }
        }
    }
    return moves;
}