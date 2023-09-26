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

int largestRectangleArea(vector<int> &a)
{
    stack<vi> stk;
    int n = a.size();
    int ans = 0;
    stk.push({0, 0});
    a.push_back(0);
    for (int i = 1; i < n + 1; i++)
    {
        if (a[i] >= a[stk.top()[0]])
        {
            stk.push({i, i});
        }
        else
        {
            vi top;
            while (!stk.empty() && a[i] < a[stk.top()[0]])
            {
                top = stk.top();
                int curr = a[top[0]];
                ans = max(ans, curr * (i - top[0] + top[0] - top[1]));
                stk.pop();
            }
            stk.push({i, top[1]});
        }
    }
    return ans;
}
int f(vi &a){
    stack<vi>stk;
    vi b = a;
    b.push_back(0);
    stk.push({0, 0});
    int n = b.size();
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(b[i] >= b[stk.top()[0]]){
            stk.push({i, i});
        }else{
            vi curr;
            while(!stk.empty() && b[stk.top()[0]] > b[i]){
                curr = stk.top();
                int temp = b[curr[0]] * (i - curr[1]);
                ans = max(ans, temp);
                stk.pop();
            }
            stk.push({i, curr[1]});
        }
    }
    return ans;
}
int main(){
    vi a = {3, 2, 1, 2, 3};
    cout<<f(a)<<endl;
    cout<<largestRectangleArea(a)<<endl;
}