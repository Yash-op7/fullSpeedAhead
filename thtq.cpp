int r[4] = {-1, 0, 1, 0};
int c[4] = {0, -1, 0, 1};

bool check(int x, int y, vector<string>& grid){
    int n = grid.size(), m = grid[0].size();
    if(x < 0 || x == n || y < 0 || y == m) return false;
    return true;
}

int Solution::solve(int n, int m, vector<string> &grid){
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[n-1][m-1] = 0;
    queue<pair<int,int>> q;
    q.push({n-1,m-1});
   
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + r[i];
            int ny = y + c[i];
            if(check(nx,ny,grid)){
                int add = 0;
                if(r[i] == -1 && c[i] == 0) {
                    if(grid[nx][ny] == 'D') add = 0;
                    else add = 1;
                }
                else if(r[i] == 1 && c[i] == 0){
                    if(grid[nx][ny] == 'U') add = 0;
                    else add = 1;
                }
                else if(r[i] == 0 && c[i] == -1){
                    if(grid[nx][ny] == 'R') add = 0;
                    else add = 1;
                }
                else{
                    if(grid[nx][ny] == 'L') add = 0;
                    else add = 1;
                }
                if(dp[nx][ny] > dp[x][y] + add) {
                    dp[nx][ny] = dp[x][y] + add;
                    q.push({nx, ny});
                }
            }
        }
    }
   
    return dp[0][0];
}