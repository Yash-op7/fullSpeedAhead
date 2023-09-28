#define ll long long
const ll MOD = 1e9 + 7;
class Solution {
public:
    int f(int idx, int sum, int total, int k, vector<int>&a, vector<vector<int>>&t){
        if(idx == a.size()){
            return 1;
        }
        if(t[idx][sum] != -1){
            return t[idx][sum];
        }
        if(a[idx] + sum < k){
            return t[idx][sum]= (f(idx+1, sum+a[idx], total, k, a, t) + f(idx+1, sum, total, k, a, t))%MOD;
        }
        return t[idx][sum]= f(idx+1, sum, total, k, a, t)%MOD;
    }
    int countPartitions(vector<int>& a, int k) {
        int n = a.size();
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        if(sum < 2*k){
            return 0;
        }
        vector<vector<int>>t(a.size(), vector<int>(k,-1));
        ll less = f(0, 0, sum, k, a, t);

        ll total =1;
        int i = 0;int x = 1;
        while(i < n-1){
            total = (total*2)%(10*MOD);i++;
        }
        
        return (2*total-2*less)%MOD;
    }
};