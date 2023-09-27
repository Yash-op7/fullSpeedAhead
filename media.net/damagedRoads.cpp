// 9:36
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define all(a) a.begin(), a.end()
#define ll long long

void f(vvi &a, vvi &b, vvb &vis, int n, int m, int &ans){
    
}

int main(){
    int n,m;
    cin>>n>>m;
    // vvi a(n, vi(m, 0));
    vvi a(n-1, vi(2, 0));
    vvi b(m-1, vi(2, 0));
    for(int i=1;i<n;i++){
        a[i][1] = i-1;
        cin>>a[i][0];
    }
    for(int j=1;j<m;j++){
        b[j][1] = j-1;
        cin>>b[j][0];
    }
    sort(all(a));
    sort(all(b));
    vvb vis(n, vb(m, false));
    int ans = 0;
    f(a, b, vis, n, m, ans);
    cout<<ans<<'\n';
}

