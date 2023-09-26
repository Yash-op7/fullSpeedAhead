class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> maxL(n, 0);
        for(int i=1;i<n;i++){
            maxL[i] = max(maxL[i-1], a[i-1]);
        }
        vector<int> maxR(n, 0);
        for(int i=n-2;i>=0;i--){
            maxR[i] = max(maxR[i+1], a[i+1]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int curr = min(maxL[i], maxR[i]);
            int sum = curr - a[i];
            if(sum > 0){
                ans+=sum;
            }
        }
        return ans;
    }
};