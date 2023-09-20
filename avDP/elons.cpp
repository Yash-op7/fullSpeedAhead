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

vi solve(int A)
{
    int n = A;
    vi XJ(n, 0);
    XJ[0] = 1;
    if (n == 1)
    {
        return {1};
    }
    XJ[1] = 1;
    for (int i = 2; i < n; i++)
    {
        XJ[i] = (XJ[i - 1] + XJ[i - 2]) % MOD;
    }
    vi ans(n, 0);
    ans[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int curr = XJ[i];
        for (int j = 0; j < 32; j++)
        {
            if ((curr >> j) & 1)
            {
                int s = (1 << j);
                int e = (1 << (j + 1));
                for (int k = s; k <= min(e, n - 1); k++)
                {
                    if (k + i < n)
                    {
                        ans[k + i] = (ans[k + i] + ans[i]) % MOD;
                    }
                }
            }
        }
    }
    return ans;
}

void print(vi &a)
{
    for (const auto &x : a)
    {
        cout << x << " ";
    }
    cout << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vi ans = solve(n);

        print(ans);
    }
}