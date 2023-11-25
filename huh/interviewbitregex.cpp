bool fun(int i, int j, const string &A, const string &B, vector<vector<int>> &dp){
    if(j<0 && i<0) return true;
   
    if(j<0 && i>=0) return false;
    if(i<0 && j>=0){
        for(int k=0; k<=j; k++){
            if(B[k] != '*') return false;
        }
        return true;
    }
    
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(A[i] == B[j] || B[j] == '?') return dp[i][j] = fun(i-1,j-1,A,B,dp);
    else if(B[j] == '*') return dp[i][j] = (fun(i,j-1,A,B,dp) | fun(i-1,j,A,B,dp) );
    else return dp[i][j] = false;
}
int Solution::isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n, vector<int> (m,-1));
    return fun(n-1,m-1,A,B,dp);
}