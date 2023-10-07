
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

// int f(int idx, int B, int C, int A, vvi &t)
// {

//     if (idx == A)
//     {
//         if (C == 0)
//         {
//             return 1;
//         }
//         return 0;
//     }
//     if (t[idx][C] != -1)
//     {
//         return t[idx][C];
//     }
//     ll ans = 0;
//     for (int i = 1; i <= B; i++)
//     {
//         if (i <= C)
//         {
//             ans += f(idx + 1, B, C - i, A, t) % MOD;
//         }
//     }
//     return t[idx][C] = ans % MOD;
// }

int fact(int x)
{
    if (x <= 1)
    {
        return 1;
    }
    return x * fact(x - 1);
}
int ncr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

long long C[1001];
void precompute()
{
    C[0] = 1;
    for (int i = 1; i < 1001; i++)
    {
        C[i] = (C[i - 1] * i) % MOD;
    }
}

long long nCr(int n, int r)
{
    if (n < r)
        return 0;
    return C[n] / ((C[r] * C[n - r]) % MOD);
}

int f(int B, int A, int C, int cA)
{
    if (A == 0 && C == 0)
    {
        return 1;
    }
    if (A <= 0)
    {
        return 0;
    }
    if (B == 0)
    {
        return 0;
    }
    int ways = C / B;
    int ans = 0;
    for (int i = 0; i <= ways; i++)
    {
        int x = nCr(A, i);
        ans += x * f(B - 1, A - i, C - i * B, cA);
    }
    return ans;
}

int Solution::findDiceSum(int A, int B, int C)
{
    // vvi t(1001, vi(1001, -1));
    // return f(0, B, C, A, t);
    // vvi t(A+1, vi(C+1, 0));
    // for(int i=0;i<=C;i++){
    //     // when we dont have any die
    //     t[0][i] = 0;
    // }
    // for(int i=1;i<=A;i++){
    //     // when we need to make sum = 0 so not possible because face of die > 0
    //     t[i][0] = 0;
    // }
    // t[0][0] = 1;
    // for(int i=1;i<=A;i++){
    //     for(int j=1;j<=C;j++){
    //         for(int k=1;k<=min(B, j);k++){
    //             t[i][j] += t[i-1][j-k] % MOD;
    //         }
    //     }
    // }
    // return t[A][C];
    precompute();
    return f(B, A, C, A);
}
