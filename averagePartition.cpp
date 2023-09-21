#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
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

bool f(int idx, int k, int sum, vi &A, vi &ans, vvvb &t)
{
    if (k == 0 && sum == 0)
    {
        return true;
    }
    if(k==0){
        return false;
    }
    if (idx == A.size())
    {
        return false;
    }
    if (!t[idx][k][sum])
    {
        return false;
    }
    bool take = false;
    if (A[idx] <= sum)
    {
        take = f(idx + 1, k - 1, sum - A[idx], A, ans, t);
        if (take)
        {
            ans.push_back(A[idx]);
            return t[idx][k][sum] = true;
        }
    }
    bool dont = f(idx + 1, k, sum, A, ans, t);
    return t[idx][k][sum] = dont;
}

vector<vector<int>> Solution::avgset(vector<int> &A)
{
    int n = A.size();
    double sum = 0;
    for (int x : A)
    {
        sum += x;
    }
    sort(all(A));

    double avg = sum / n;
    vi ans1;
    vi ans2;
    vvi ans;
    vvvb t(101, vvb(101, vb(5001, true)));
    for (int i = 1; i <= n; i++)
    {
        double temp = avg * i;
        if ((temp - (int)(temp) == 0) && f(0, i, (int)temp, A, ans1, t))
        {
            sort(all(ans1));
            ans.push_back(ans1);
            for (int x : ans1)
            {
                A.erase(find(all(A), x));
            }
            ans.push_back(A);
            if(A.size() == 0 || ans1.size() == 0){
                return {};
            }
            return ans;
        }
    }
    return ans;
}
