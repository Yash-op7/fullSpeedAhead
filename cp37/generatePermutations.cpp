#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

void print(vi &a){
    for(auto x:a){
        cout<<x<<" ";
    }
    cout<<endl;
}

void func(int idx, vi &a){
    if(idx == a.size()){
        print(a);
        return;
    }
    for(int i = idx;i<a.size();i++){
        swap(a[i] , a[idx]);
        func(idx+1, a);
        swap(a[i], a[idx]);
    }

}

int main()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    func(0, a);
}