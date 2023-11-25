// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

    #define vb vector<bool>
    #define vvb vector<vb>
#define vi vector<int>
vi dx = {0, 0, -1, 1};
vi dy = {1, -1, 0, 0};

int dfs(int x, int y, vvb &grid, vvb &visited){
    int n = grid.size(), m = grid[0].size();
    if(x == n-1 && y == m-1){
        return 0;
    }
    int ans = 1e9;
    for(int i=0;i<4;i++){
        int tx  = x+ dx[i], ty = y + dy[i];
        if(tx < n && tx >=0 && ty<m && ty>=0 && grid[tx][ty] && !visited[tx][ty]){
            visited[tx][ty] = true;
            ans = min(ans ,(1+ dfs(tx, ty, grid, visited)));
            visited[tx][ty] = false;
        }
    }
    return ans;

}

int solution(int n, int m, vector<int> &X1, vector<int> &Y1, vector<int> &X2, vector<int> &Y2) {
    // Implement your solution here
    vvb grid(n, vb(m, true));
    int N = X1.size();d
    for(int i=0;i<X1.size();i++){
        for(int x=X1[i];x<=X2[i];x++){
            for(int y=Y1[i];y<=Y2[i];y++){
                grid[x][y]=false;
            }
        }
    }
    if(!grid[0][0]){
        return -1;
    }
    vvb visited(n, vb(m, false));
    int ans = dfs(0, 0, grid, visited);
    if(ans >= 1e9){
        return -1;
    }
    return ans;

}