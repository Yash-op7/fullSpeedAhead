
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

class Solution
{
    int kadane(vi &temp){
        int ans = INT_MIN;
        int sum = 0;
        bool allNeg = true;
        for(int x:temp){
            sum += x;
            if(sum < 0){
                sum = 0;
            }
            ans = max(ans, sum);
            if(x >= 0){
                allNeg = false;
            }
        }
        if(allNeg){
            int c = INT_MIN;
            for(int x:temp){
                c = max(c, x);
            }
            return c;
        }else{
            return ans;
        }
    }
public:
    int maximumSumRectangle(int r, int c, vector<vector<int>> grid)
    {
        // code here
        int ans = INT_MIN;
        // 19:37
        vi temp(c, 0);
        for(int i=0;i<r;i++){
            for(int j=i;j<r;j++){
                if(i == j){
                    temp = grid[i];
                }else{
                    // make temp
                    for(int k=0;k<c;k++){
                        temp[k] += grid[j][k];
                    }
                }
                ans = max(ans, kadane(temp));
            }
        }
        return ans;
    }
};          