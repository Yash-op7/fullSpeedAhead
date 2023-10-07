#define vi vector<int>
int f2(vi &a){
    stack<int> stk;
    stk.push(0);
    a.push_back(0);
    int i=1;
    int ans = 0;
    while(i<a.size()){
        while (!stk.empty() &&  a[stk.top()] > a[i])
        {
            int t=  stk.top();
            int h = a[t];
            stk.pop();
            if(stk.empty()){
                ans = max(ans ,h*i);
            }else{
                int len = i - stk.top()-1;
                ans = max(ans, h*len);
            }
        }
        stk.push(i);
        i++;
    }
    return ans; 
}
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return f2(heights);
    }
};