// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#includE<
vector<int> dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};

int f(int x, int y, vector<vector<bool>>&maze, vector<vector<bool>>&vis){
    int n = maze.size(), m = maze[0].size();
    if(x == n-1 && y == m-1){
        return 0;
    }
    int ans = 1e9;
    for(int i=0;i<4;i++){
        int tx  = x+ dx[i], ty = y + dy[i];
        if(tx < n && tx >=0 && ty<m && ty>=0 && maze[tx][ty] && !vis[tx][ty]){
            vis[tx][ty] = true;
            ans = min(ans,1+ f(tx, ty, maze, vis));
            vis[tx][ty] = false;
        }
    }
    if(ans >= 1e9){
        return -1;
    }else{
        return ans;
    }

}

int solution(int n, int m, vector<int> &X1, vector<int> &Y1, vector<int> &X2, vector<int> &Y2) {
    // Implement your solution here
    vector<vector<bool>>maze(n, vector<bool>(m, true));
    for(int i=0;i<X1.size();i++){
        for(int x=X1[i];x<=X2[i];x++){
            for(int y=Y1[i];y<=Y2[i];y++){
                maze[x][y]=false;
            }
        }
    }
    if(!maze[0][0]){
        return -1;
    }
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    return f(0, 0, maze, vis);

}
int main(){

}