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
    if (k == 0)
    {
        if (sum == 0)
        {
            return true;
        }
        return false;
    }
    int n = A.size();
    if (idx == n)
    {
        return false;
    }
    if (!t[idx][k][sum])
    {
        return false;
    }
    if (A[idx] <= sum)
    {
        ans.push_back(A[idx]);
        bool take = f(idx + 1, k - 1, sum - A[idx], A, ans, t);
        if (take)
        {
            return  true;
        }
        ans.pop_back();
    }
    if (f(idx + 1, k, sum, A, ans, t))
    {
        return true;
    }
    return t[idx][k][sum] = false;
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
    vvvb t(101, vvb(101, vb(5001, true))); // 5 x 1e7
    for (int i = 1; i < n; i++)
    {
        double temp = avg * i;
        if ((temp - (int)(temp) == 0) && f(0, i, (int)temp, A, ans1, t))
        {
            int loc = 0;
            for(int num : ans1){
                while(loc < n && A[i] != num){
                    ans2.pus
                }
            }
            sort(all(ans1));
            if (A.size() < ans1.size())
            {
                ans.push_back(A);
                ans.push_back(ans1);
            }
            else
            {
                ans.push_back(ans1);
                ans.push_back(A);
            }
            return ans;
        }
    }
    return {};
}
