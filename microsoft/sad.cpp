int dfs(int row, int col , vector<vector<int>> &grid, vector<vector<int>> &vis, int r[], int c[], int n, int m){
        int ans = 0;
        vis[row][col] = 1;
        for(int i=0; i<4; i++){
            int drow = row+ r[i];
            int dcol = col + c[i];

            if(drow>=0 && drow<n && dcol >=0 && dcol <m){
                int temp = abs(grid[drow][dcol]-grid[row][col]);
                if((temp==1 || temp == 0) && vis[drow][dcol] == 0){
                    ans = ans + dfs(drow, dcol, grid, vis, r, c, n, m);
                }
            }
        }
        return ans +1;

        
    }
int solution(vector< vector<int> > &A) {
    int n =A.size();
    int m = A[0].size();
    vector<vector<int>> vis(n,vector<int> (m,0));
    int r[] = {-1,0,1,0};
    int c[] = {0,-1,0,1};
    int ans = 0;
     for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0) ans = max(ans, dfs(i, j, A, vis, r, c, n , m));
            }
        }
        return ans;
}