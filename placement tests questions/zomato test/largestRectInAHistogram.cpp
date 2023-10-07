
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

int largestRectangle(vector<int> &a)
{
    // Write your code here.
    stack<vi> stk;
    stk.push({0, 0});
    vi b = a;
    b.push_back(00);
    int n = b.size();
    int ans = 0;
    for(int i=1;i<n;i++){
        if(b[i] > b[stk.top()[0]]){
            stk.push({i, i});
        }else{
            vi curr;
            while(!stk.empty() && b[stk.top()[0]] > b[i]){
                 curr = stk.top();
                stk.pop();
                int temp = b[curr[0]] * (i - curr[0] + curr[0]- curr[1]);
                ans = max(ans, temp);
            }
            stk.push({i, curr[1]});
        }
    }
    return ans;

}