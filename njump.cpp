
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


bool f(int idx, int j, vi &a){
    int n = a.size();
    if(idx == n-1){
        return true;
    }
    bool jumpHigh = false;
    if(j%2 != 0){
        jumpHigh = true;
    }
    for(int i=idx + 1;i<n;i++){
        if(jumpHigh){
            if(a[i] >= a[idx] && f(i, j + 1, a)){
                return true;
            }
        }else{
            if(a[i] <= a[idx] && f(i, j+1, a)){
                return true;
            }
        }
    }
    return false;
}

int ninjaJump(vector<int> &x,int n)
{
    int ans = 0;
    for(int i=0;i<n;i++){
        if(f(i, 1, x)){
            ans++;
        }
    }
    return ans;
}











