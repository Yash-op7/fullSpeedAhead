

int f(int idx, int rem, vector<int>&a, int k, vector<vector<int>>&t){
    if(idx == a.size()){
        return 0;
    }
    if(rem <= 0){
        return 0;
    }
    if(t[idx][rem] != -1){
        return t[idx][rem];
    }
    int take = a[idx] + f(idx+1, k, a, k, t);
    int notTake = f(idx+1, rem-1, a, k, t);
    return t[idx][rem]= max(take, notTake);
}

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<vector<int>>t(nums.size(), vector<int>(k+1, -1));
        int ans = f(0, k, nums, k, t);
        if(ans != 0){
            return ans;
        }
        int largest = INT_MIN;
        for(int i:nums){
            largest = max(largest, i);
        }
        return largest;
    }
};