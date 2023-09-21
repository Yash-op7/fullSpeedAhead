#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define all(x) x.begin(), x.end()

vector<vector<int>> danceTogether(vector<vector<int>> &edges, int n, int m, int k)
{
    // Write your code here
    vb vis(m+1, false);
    vvi adj(n + 1);
    vvi degree(n + 1, vi(2, 0));
    for (vi x : edges)
    {
        adj[x[0]].push_back(x[1]);
        degree[x[0]][0]++;
        degree[x[0]][1] = x[0];
    }
    sort(all(degree));
    vvi ans;
    for(auto &x:degree){
        int partner=0;
        if(x[1] == 0){
            continue;
        }
        bool done = false;
        while(x[0] > 0 && partner != -1){
            for(int g:adj[x[1]]){
                if(!vis[g]){
                    partner = g;
                    vis[g] = true;
                    ans.push_back({x[1], g});
                    x[0]--;
                    done = true;
                    break;
                }
            }
            if(done){
                break;
            }
            if(partner == 0){
                partner = -1;
            }else{
                partner = 0;
            }

        }
    }
    return ans;
}

int main()
{
    int n, m, k;
    int tt;
    cin >> tt;
    while (tt--)
    {
        vvi edges;
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            edges.push_back({x, y});
        }
        vvi ans = danceTogether(edges, n, m, k);
        for (auto edge : ans)
        {
            cout << edge[0] << " " << edge[1] << endl;
        }
        cout<<'\n';
    }
}