#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

vi dx = {0, 0, -1, 1};
vi dy = {1, -1, 0, 0};

int f(int x, int y, vvi&maze, vector<vector<bool>>&vis){
    int l = -1, r=-1, d=-1, u=-1;
    int ans = 0;
    int n = vis.size();
    int m = vis[0].size();
    for(int i=0;i<4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx < n && tx >=0&& ty >=0 && ty <m && !vis[tx][ty] &&maze[tx][ty] != 0)
        {
            vis[tx][ty] = true;
            ans = max(ans, f(tx, ty, maze, vis));
        }
    }
    return maze[x][y] + ans;
}
int main(){
    int m, n;
    cin>>m>>n;
    vvi maze(m, vi(n, 0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(maze[i][j] != 0){
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                vis[i][j] = true;
                ans = max(ans, f(i, j, maze, vis));
            }
        }
    }
    cout<<ans<<'\n';
}