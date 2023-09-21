class Solution {
public:
    long long fn(int i, int even, vector<int>& nums, int &x, vector<vector<int>> &dp){
        int n = nums.size();
        if(i==n) return dp[i][even] = 0;
        if(dp[i][even] != -1) return dp[i][even];
        int notTake = fn(i+1, even, nums, x, dp);
        int take = 0;
        int chk = (nums[i]%2==0)?1:0;
        if(even == chk) take = nums[i]+fn(i+1, chk, nums, x, dp);
        else take = nums[i]-x+fn(i+1, chk, nums, x, dp);
        return dp[i][even] = max(take, notTake);
    }
    long long maxScore(vector<int>& nums, int x) {
        int even = (nums[0]%2==0)?1:0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return nums[0] + fn(1, even, nums, x, dp);
    }
};