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
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vi s(n, 0);
        vi e(n, 0);
        for(int i=0;i<n;i++){
            cin>>s[i]>>e[i];;
        }
        
        int ps = s[0];
        int w = ps;
        int pe = e[0];
        int cnt = 0;
        int ans=0;
        for(int i=1;i<n;i++){
            if(s[i] >= ps && e[i] >= pe){
                ans = -1;
                break;
            }
        }
        if(ans != -1){
            cout<<w<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
}