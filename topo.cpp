
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
    bool isPossible(int N, int P, vector<pair<int, int>> &p)
    {
        // Code here
        vvi adj(N);
        vi indegree(N, 0);
        for (auto x : p)
        {
            adj[x.second].push_back(x.first);
            indegree[x.first]++;
        }
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        vi ans;
        while (!q.empty())
        {
            int front = q.front();
            cnt++;
            ans.push_back(front);
            q.pop();
            for (auto x : adj[front])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        return ans;
    }
};