// 9:36
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define all(a) a.begin(), a.end()
#define ll long long
const int MOD = 1e9;

int main(){
    int n,m;
    cin>>n>>m;
    vi a(n-1, 0);
    vi b(m-1, 0);
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int j=0;j<m-1;j++){
        cin>>b[j];
    }
    vvb vis(n, vb(m, false));
    vis[0][0] = true;
    queue<vi>q;
    q.push({0, 0});
    vi dx = {0,0,-1,1};
    vi dy = {1, -1, 0, 0};
    while(!q.empty()){
        vi curr = q.front();
        q.pop();
        int i= curr[0];
        int j= curr[1];
        int up, down, left, right;
        up = down = left = right = 1e9;
        if (i - 1 >= 0 && !vis[i-1][j])
        {
            up = a[i - 1];
        }
        if (j - 1 >= 0 && !vis[i][j-1])
        {
            left = b[j - 1];
        }
        if (i + 1 < n  && !vis[i+1][j ])
        {
            down = a[i];
        }
        if (j + 1 < m  && !vis[i][j + 1])
        {
            right = b[j];
        }
        if ((min(min(up, down), min(left, right))) == 1e9){
            break;
        }
        ans = (ans + min(min(up, down), min(left, right))) % MOD;
        if ((min(min(up, down), min(left, right))) == up)
            {
                q.push({i - 1, j});
                vis[i - 1][j] = true;
            }
        else if ((min(min(up, down), min(left, right))) == down)
        {
            q.push({i + 1, j});
            vis[i + 1][j] = true;
        }
        else if ((min(min(up, down), min(left, right))) == left)
        {
            q.push({i, j-1});
            vis[i][j-1] = true;
        }else{
            q.push({i, j + 1});
            vis[i][j + 1] = true;
        }
    }
    cout<<ans<<'\n';
}

