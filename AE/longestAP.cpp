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

int f(int idx, int d, const vi &a){
    if(idx == a.size()){
        return 0;
    }
    int n = a.size();
    int ans = 1;
    if(d == -1e9){
        for(int i=idx+1;i<n;i++){
            ans = max(ans, 1 + f(i, a[i] - a[idx], a));
        }
        return ans;
    }else{
        for(int i=idx+1;i<n;i++){
            if(a[i]  - a[idx] == d){
                return 1 + f(i, d, a);
            }
        }
    }
    return 1;
}

int solve(const vector<int> &A) {
    int n = A.size();
    vi t(n, 1);
    return f(0, -1e9, A);
}
