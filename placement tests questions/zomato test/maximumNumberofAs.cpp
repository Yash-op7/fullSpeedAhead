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

int f(int n, int buff ,int curr){
    if(n == 0){
        return curr;
    }
    // 3 ops
    int ans = 0;
    if(buff != 0){
        ans = max(ans, f(n-1, buff, curr+buff));
    }
    ans = max(ans, f(n-1, buff, curr+1));
    if(n>=2){
        ans = max(ans, f(n-2, curr, curr));
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<f(n-1, 0 ,1)<<'\n';
}