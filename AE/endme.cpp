
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

int findDiceSum(int A, int B, int C)
{
    // vector<vector<int>>dp(A+1,vector<int>(C+1,0));
    int N = 1e9 + 7;
    vector<long long int> prev(C + 1, 0);
    prev[0] = 1;
    for (int i = 1; i <= A; i++)
    {
        vector<long long int> curr(C + 1, 0);
        for (int j = 1; j <= C; j++)
        {
            prev[j] += prev[j - 1];
        }
        for (int j = 1; j <= C; j++)
        {
            if (j - B - 1 >= 0)
            {
                curr[j] = ((prev[j - 1] - prev[j - B - 1]) + N);
            }
            else
            {
                curr[j] = prev[j - 1];
            }
        }
        prev = curr;
    }
    return prev[C];
}