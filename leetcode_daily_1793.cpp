class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        priority_queue<int, vector<int>, greater<int>>minHeap;
        int l = k;int r = k;
        int n = a.size();
        minHeap.push(a[k]);
        int ans = -1;
        while(true){
            while(l>=0 && a[l] >= minHeap.top()){
                l--;
            }
            l++;
            while(r<n && a[r] >= minHeap.top()){
                r++;
            }
            r--;
            ans = max(ans, minHeap.top()*(r-l+1));
            if(l == 0 && r == n-1){
                return ans;
            }
            else if(l == 0){
                minHeap.push(a[r+1]);
            }else if(r == n-1){
                minHeap.push(a[l-1]);
            }else{
                if(a[l-1] > a[r+1]){
                    minHeap.push(a[l-1]);
                }else{
                    minHeap.push(a[r+1]);
                }
            }

        }
        return ans;
    }
};