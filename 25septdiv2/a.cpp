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


int main(){
    int n;
    int tt;
    cin>>tt;
    while(tt--){
        cin>>n;
        vi a(n);
        vector<set<int>>test;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int b = 1;
        for(int i=0;i<n;i++){
            if(b == a[i]){
                b++;
            }
            b++;
        }
        cout<<b-1<<'\n';
    }
}