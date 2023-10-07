
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

class Solution
{
    int f(int idx, int k, int mustSelect, int mustNot, vi &a)
    {
        if (idx == a.size())
        {
            if (k > mustSelect && k < mustNot)
            {
                return 1;
            }
            return 0;
        }
        ll ans = 0;
        int select = f(idx + 1, k + 1, max(a[idx], mustSelect), mustNot, a);
        int dont = f(idx + 1, k, mustSelect, min(mustNot, a[idx]), a);
        return select + dont;
    }

public:
    int countWays(vector<int> &nums)
    {
        return f(0, 0, -1, INT_MAX, nums);
    }
};