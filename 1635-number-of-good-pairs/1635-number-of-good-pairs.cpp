class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int > k;
        for(int x:nums){
            k[x]++;
        }
        int ans = 0;
        for(auto x:k){
            int temp = x.second;
            ans += temp*(temp-1)/2;
        }
        return ans;
    }
};