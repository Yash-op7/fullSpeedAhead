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
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin>>n>>m;
        vi a(n, 0);
        vi b(m, 0);
        int xorA = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            xorA = xorA ^ a[i];
        }
        int orB = 0;
        int ans1 = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            orB = orB | b[i];
        }
        int ans2 = 0;
        if (n % 2 == 0)
        {
            ans2 = xorA;
            for(int i=31;i>=0;i--){
                int b1 = (xorA>>i) & 1;
                int b2 = (orB>>i) & 1;
                if(b1 == 1 && b2 != 1){
                    ans1 = ans1 | (1<<i);
                }
            }
            cout<<ans1<<" "<<ans2<<endl;
        }
        else
        {
            ans2 = (xorA | orB);
            cout<<xorA<<" "<<ans2<<endl;
        }
    }
}