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

int solve(int n, int m, vector<string> &maze)
{
    vvi dist(n, vi(m, 1e9));
    dist[0][0] = 0;
    pq<vi, vvi, greater<vi>> q;
    q.push({0, 0, 0});
    vi dx = {-1, 0, 0, 1};
    vi dy = {0, 1, -1, 0};
    while(!q.empty()){
        vi curr = q.top();
        q.pop();
        char c = maze[curr[0]][curr[1]];
        for(int i=0;i<4;i++){
            int tx = curr[0] + dx[i];
            int ty = curr[1] + dy[i];
            
        }
    }
}
