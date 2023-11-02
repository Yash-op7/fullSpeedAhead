int dfs(int i, int j, vector<vector<int>> &vis, int drow[], int dcol[],int A, int B, vector<string> &C){
    if(i==A-1 && j== B-1) return 0;
    vis[i][j] =1;
    int ans = 1e9;
    for(int k=0; k<4; k++){
        int row = i+ drow[k];
        int col = j+ dcol[k];
        if(row>=0 && row < A && col>=0 && col<B && vis[row][col] ==0){
            if(C[i][j] == 'R' && col-j == 1 && row-i == 0) ans = min(ans, dfs(row,col,vis, drow, dcol, A,B,C));
            else if(C[i][j] == 'L' && col-j == -1 && row-i == 0) ans = min(ans, dfs(row,col,vis, drow, dcol, A,B,C));
            else if(C[i][j] == 'U' && row-i == -1 && col-j == 0) ans = min(ans, dfs(row,col,vis, drow, dcol, A,B,C));
            else if(C[i][j] == 'D' && row-i== 1 && col-j == 0) ans = min(ans, dfs(row,col,vis, drow, dcol, A,B,C));
            ans = min(ans, 1+dfs(row,col,vis, drow, dcol, A,B,C));
        }
    }
    return ans;
}
int Solution::solve(int A, int B, vector<string> &C) {
    int drow[4] = {0, 1, -1, 0}; 
    int dcol[4] = {1, 0, 0, -1};
    vector<vector<int>> vis(A, vector<int> (B,0));
    return dfs(0,0,vis,drow,dcol,A,B,C);
    
}