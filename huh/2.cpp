#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &A, vector<long long> &sum)
{

    sum[node] = A[node - 1];

    for (auto child : graph[node])
    {
        if (child == parent)
            continue;

        dfs(child, node, graph, A, sum);
        sum[node] += sum[child];
    }
}
int deleteEdge(vector<int> &A, vector<vector<int>> &B)
{

    const int mod = 1e9 + 7;
    int n = A.size();
    vector<vector<int>> graph(1e5 + 1);
    for (int i = 0; i < B.size(); i++)
    {
        int u = B[i][0];
        int v = B[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<long long> sum(n + 1, 0);

    dfs(1, -1, graph, A, sum);
    long long res = 0;
    long long s = 0;
    for (int i = 0; i < n; i++)
        s = s + A[i];

    for (int i = 0; i <= n; i++)
    {
        long long part1 = sum[i];
        long long part2 = s - part1;
        res = max(res, (part1  * part2 ) % mod);
    }
    return res % mod;
}