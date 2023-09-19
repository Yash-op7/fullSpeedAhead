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

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,k,x;
        cin>>n>>k>>x;
        ll ans = 0;
        if( x < k-1 || n < k){
            cout<<-1<<endl;
            continue;
        }
        ans = (k*(k-1))/2;
        int temp = (x == k)?x-1:x;
        ans += (n-k)*(temp);
        cout<<ans<<endl;
    }
}