
#define vi vector<int> 
#define vvi vector<vi>

int f(vi &a){
    stack<vi>stk;
    vi b = a;
    b.push_back(0);
    stk.push({0, 0});
    int n = b.size();
    int ans = 0;
    for(int i=1;i<n;i++){
        if(b[i] >= b[stk.top()[0]]){
            stk.push({i, i});
        }else{
            vi curr;
            while(!stk.empty() && b[stk.top()[0]] > b[i]){
                curr = stk.top();
                int temp = b[curr[0]] * (i - curr[0] + curr[0] - curr[1]);
                ans = max(ans, temp);
                stk.pop();
            }
            stk.push({i, curr[1]});
        }
    }
    return ans;
}

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vvi pref(n, vi(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0){
                    pref[i][j] = a[i][j] - '0';
                }else{
                    if(a[i][j] == '1'){
                        pref[i][j] = pref[i-1][j]+(a[i][j] - '0');
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, f(pref[i]));
        }
        return ans;
    }
};