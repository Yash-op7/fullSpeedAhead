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
        // vector<set<int>>a;
        vvi a(n);
        vi cnt(50, 0);
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            vi temp(k);
            for(int j=0;j<k;j++)
            {
                cin>>temp[j];
                cnt[temp[j] - 1]++;
            }
            a[i] = temp;
        }
        int ans = INT_MAX;
        for(const vi s:a){
            int curr=0;
            for(const int x:s){
                if(cnt[x-1] == 1){
                    curr++;
                }
            }
            if(curr>0){
                ans = min(ans, curr);
            }
        }
        int m = 0;
        for(int i=0;i<50;i++){
            if(cnt[i]>0){
                m ++;
            }
        }
        cout<<m<<" "<<ans<<'\n';
    }
}