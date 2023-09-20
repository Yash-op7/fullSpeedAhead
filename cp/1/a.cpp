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

void print(vi &a)
{
    for (const auto &x : a)
    {
        cout << x << " ";
    }
    cout << '\n';
}

bool func(vi &a, vi &b){
    return a[0] > b[0];
}

bool func2(vi &a, vi &b){
    return a[1] < b[1];
}

vi solve(vi &a){
    int n = a.size();
    vvi arr(n, vi(2));
    for(int i=0;i<n;i++){
        arr[i][0] = a[i];
        arr[i][1] = i;
    }
    sort(all(arr), func);
    for(int i=0;i<n;i++){
        arr[i][0] = i+1;
    }
    sort(all(arr), func2);
    for(int i=0;i<n;i++){
        a[i] = arr[i][0];
    }
    return a;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vi a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vi ans = solve(a);
        print(ans);
    }
}