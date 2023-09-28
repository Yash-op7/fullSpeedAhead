#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 

class Solution {
public:
    bool f(int idx, int val, int mask, vi &a, vector<vector<vector<bool>>>&t){
        if(val == 0){
            return true;
        }
        if(idx == a.size()){
            return false;
        }
        if(!t[idx][val][mask]){
            return false;
        }
        if((mask>>idx & 1) == 1){
            return t[idx][val][mask]= f(idx+1, val, mask, a, t);
        }
        if(val >= a[idx]){
            return t[idx][val][mask]= f(idx+1, val-a[idx], (mask | (1<<idx)), a, t) || f(idx+1, val, mask, a, t);
        }
        return t[idx][val][mask]= f(idx+1, val, mask, a, t);
    } 
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum % k != 0){
            return false;
        }
        int val = sum/k;
        int mask = 0;
        vector<vector<vector<bool>>> t(nums.size(), vector<vector<bool>>(val + 1, vector<bool>((1 << 16), true)));
        for(int i=0;i<k-1;i++){
            if(!f(0, val, mask, nums, t)){
                return false;
            }
        }
        return true;
    }
};






