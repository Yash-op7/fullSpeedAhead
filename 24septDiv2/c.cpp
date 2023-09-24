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
const int MOD = 998244353;

long long C[200001];
void precompute()
{
    C[0] = 1;
    for (int i = 1; i < 200001; i++)
    {
        C[i] = (C[i - 1] * i) % MOD;
    }
}


ll f1(int idx, string &s){
    if (idx == s.length() - 1)
    {
        return 0;
    }
    if (s[idx] == s[idx + 1])
    {
        return (1 + f1(idx + 1, s));
    }
    else
    {
        return f1(idx + 1, s);
    }
}

int main()
{
    int tt;
    cin >> tt;
    string s;
    getline(cin, s);
    precompute();

    while (tt--)
    {
        getline(cin, s);
        int ans1=f1(0, s);

        ll k = 1;
        int cnt = 0;int n = s.length();
        for(int i=0;i<s.length()-1;i++){
            if(s[i] == s[i+1]){
                int j=i+1;
                int currCnt = 1;
                while(j<n && s[i] == s[j]){
                    currCnt++;
                    j++;
                }
                i = j-1;
                k = (k*currCnt)%MOD;
                cnt += currCnt-1;
            }
        }
        ll ans2 = (k * C[cnt])%MOD;
        cout<<ans1<<" "<<ans2<<'\n';
    }
}
