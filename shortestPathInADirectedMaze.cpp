
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

int solve(int n, int m, vector<string> &C)
{
    vvi adj[n * m];
    vi dx = {-1, 0, 0, 1};
    vi dy = {0, 1, -1, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int currNode = i * m + j;
            char c = C[i][j];
            int free = 0;
            if (c == 'R')
            {
                free = 1;
            }
            else if (c == 'D')
            {
                free = 3;
            }
            else if (c == 'L')
            {
                free = 2;
            }
            for (int k = 0; k < 4; k++)
            {
                int tx = i + dx[k];
                int ty = j + dy[k];
                if (tx < n && tx >= 0 && ty >= 0 && ty < m)
                {
                    int currNeighbour = tx * m + ty;
                    adj[currNode].push_back({currNeighbour, (free == k ? 0 : 1)});
                }
            }
        }
    }
    int src = 0;
    int dest = (n - 1) * m + m - 1;
    vi dist(n*m, 1e9);
    dist[0] = 0;

    pq<vi, vvi, greater<vi>> q;
    q.push({0,0});
    while(!q.empty()){
        vi top = q.top();
        q.pop();
        for(auto x:adj[top[1]]){
            int next = x[0];
            int cost = x[1];
            if(dist[next] > cost + dist[top[1]]){
                dist[next] = cost + dist[top[1]];
                q.push({dist[next], next});
            }
        }
    }
    return dist[dest];
}

int main()
{
    int n, m;

    cin >> n >> m;
    vector<string> c(n);
    getline(cin, c[0]);
    ;
    for (int i = 0; i < n; i++)
    {
        getline(cin, c[i]);
    }
    cout << solve(n, m, c) << endl;
}