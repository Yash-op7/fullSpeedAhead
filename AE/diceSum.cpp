
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

int f(int idx, int B, int C, int A, vvi &t)
{

    if (idx == A)
    {
        if (C == 0)
        {
            return 1;
        }
        return 0;
    }
    if (t[idx][C] != -1)
    {
        return t[idx][C];
    }
    ll ans = 0;
    for (int i = 1; i <= B; i++)
    {
        if (i <= C)
        {
            ans += f(idx + 1, B, C - i, A, t) % MOD;
        }
    }
    return t[idx][C] = ans % MOD;
}

int Solution::findDiceSum(int A, int B, int C)
{
    vvi t(1001, vi(1001, -1));
    return f(0, B, C, A, t);
}
