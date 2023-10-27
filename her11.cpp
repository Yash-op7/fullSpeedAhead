// class Solution {
// public:
//     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
//     }
// };

#define vi vector<int>
int solve(vector<int> &a){
    int n = a.size(), l = 0, r = n-1;
    set<vi> minHeap;
    set<vi, vector<vi>, greater<vi>>maxHeap;
    for(int i=0;i<n;i++){
        maxHeap.insert({a[i], i});
        minHeap.insert({a[i], i});
    }
    int ans = 0;
    while(minHeap.top()[0]*2 < maxHeap.top()[0] && l <= r){
        int loc_min = minHeap.top()[1]
        int loc_max = maxHeap.top()[1];
        int dist1 = min(abs(l-loc_min), abs(r-loc_min));
        int dist2 = min(abs(l-loc_max), abs(r-loc_max));
        if(dist1 < dist2){
            // need to remove the smaller element;
            if(abs(l-loc_min) < abs(r-loc_min)){
                while(l<= loc_min){
                    minHeap.erase({a[l], l});
                    l++;
                    ans++;
                }
            }else{
                while(r>=loc_min){
                    minHeap.erase({a[r], r});
                    r--;
                    ans++;
                }
            }
        }else{
            // its more optimal to remove the larger element
            if(abs(l-loc_max) < abs(r-loc_max)){
                while(l<= loc_max){
                    maxHeap.erase({a[l], l});
                    l++;
                    ans++;
                }
            }else{
                while(r>=loc_max){
                    maxHeap.erase({a[r], r});
                    r--;
                    ans++;
                }
            }
        }
    }
    return ans;
}