class Solution {
public:
    int f(int x){
        int ans = 0;
        for(int i=0;i<32;i++){
            if((x>>i )& 1){
                ans++;
            }
        }return ans;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            if(f(i) == k){
                sum += nums[i];
            }
        }
        return nums;
    }
};