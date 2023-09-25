
#define vi vector<int>
class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<vi> stk;
        int n = a.size();
        int ans = 0;
        stk.push({0, 0});
        a.push_back(0);
        for(int i=1;i<n+1;i++){
            if(a[i] >= a[stk.top()[0]]){
                stk.push({i, i});
            }else{
                vi top;
                while(!stk.empty() && a[i] < a[stk.top()[0]]){
                    top = stk.top();
                    int curr = a[top[0]];
                    ans = max(ans, curr*(i-top[0] + top[0] - top[1]));
                    stk.pop();
                }
                stk.push({i, top[1]});
            }
        }
        return ans;
    }
};