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

ll f(ll k, ll s1, ll s2){
    ll cnt = 0;

    while((k >= s2*cnt) && (((k - (s2 * cnt) )/s1) + cnt == (k / s1))){
        cnt++;
    }
    if(cnt == 0){
        return 0;
    }
    return cnt-1;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin>>n;
        vi c(n ,0);
        int smallest = 0;
        for(int i=0;i<n;i++){
            cin>>c[i];
            if(c[i] <= c[smallest]){
                smallest = i;
            }
        }
        int k;
        cin>>k;
        int sec = smallest + 1;
        if(sec < n){
            for (int i = sec; i < n; i++)
            {
                if(c[i] <= c[sec]){
                    sec = i;
                }
            }

            ll cnt = f(k, c[smallest], c[sec]);
            ll val2 = cnt;
            ll val1 = k/(c[smallest]);
            for(int i=0;i<=smallest;i++){
                cout<<val1<<" ";
            }
            for(int i=smallest+1;i<=sec;i++){
                cout<<val2<<" ";
            }   
            for(int i=sec+1;i<n;i++){
                cout<<0<<" ";
            }
            cout<<'\n';

        }else{
            int ans = k/c[smallest];
            for(int i=0;i<n;i++){
                if(i<=smallest){
                    cout<<ans<<" ";
                }else{
                    cout<<0<<" ";
                }
            }
            cout<<'\n';
        }
        
    }
}