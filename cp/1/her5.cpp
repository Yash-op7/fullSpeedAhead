int mod = 1e9+7;
int fn(int i, string &a, vector<int> &dp){
    int n = a.size();
    if(i==n-1) {
        if(a[i]== '0') return dp[i] = 0;
        return 1;
    }
    if(i==n) return dp[i] = 1;
    if(a[i+1] == '0') {
        if(a[i] > '2') return 0;
        return dp[i] = fn(i+2, a, dp)%mod;
    }
    if(dp[i]!= -1) return dp[i];
    if(a[i] == '1'){
        return dp[i] = (fn(i+1, a, dp)%mod + fn(i+2, a, dp)%mod)%mod;
    } 
    if(a[i]=='2'){
        if(a[i+1]> '6') return dp[i] = fn(i+1, a, dp)%mod;
        return dp[i] = (fn(i+1, a, dp)%mod + fn(i+2, a, dp)%mod)%mod;
    }
    return dp[i] = fn(i+1, a, dp)%mod;
}
int Solution::numDecodings(string a) {
    int n = a.size();
    if(n==0) return 0;
    vector<int> dp(n+1, -1);
    return fn(0, a, dp);
}