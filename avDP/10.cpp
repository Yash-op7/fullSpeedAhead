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

int main()
{
    int n;
    cin >> n;
    vi a(n, 0);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        k+=a[i];
    }
    int t[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        t[0][i] = 0;
    }
    int w = k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (a[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - a[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    vi last;
    for(int i=0;i<=w;i++){
        last.push_back(t[n][i]);
    }
    int ans = INT_MAX;
    int cnt = 0;
    int diff; 
    cin>>diff;
    cout<<"diff is "<<diff<<endl;
    for(int i=0;i<=w;i++){
        if(last[i] > 0){
            // ans = min(ans, w - 2*i);
            if(w - i == diff){
                if(last[diff] > 0){
                    cnt+= last[diff] * last[i];
                }
            }
        }
    }
    cout<<last[(w+diff)/2]<<endl;
    // cout<<ans<<endl;
}