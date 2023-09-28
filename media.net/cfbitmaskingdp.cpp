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

int f(int idx, int mask, int k, vi &a, vvi&s){
    int n = a.size();
    if(mask == )
    if(idx == n){
        return -1e9;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p, k;
    cin>>n>>p>>k;
    vi a(n, 0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vvi s(n, vi(p, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cin>>s[i][j];
        }
    }
    cout<<f(0, 0, k, a, s);
}