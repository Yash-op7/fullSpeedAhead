#include <bits/stdc++.h>
using namespace std;
int f(int idx, int last, int d, bool done, vector<int> &a, map<vector<int>, int> &t)
{
    if (idx == a.size())
    {
        return done;
    }
    if (t.find({idx, last, d, done}) != t.end())
    {
        return t[{idx, last, d, done}];
    }
    if (last == -1)
    {
        return t[{idx, last, d, done}] = f(idx + 1, idx, d, done, a, t) + f(idx + 1, last, d, done, a, t);
    }
    else
    {
        if (!done)
        {
            if (d == -1)
            {
                if ((long long)a[idx] - a[last] <= (long long)INT_MAX && (long long)a[idx] - a[last] >= (long long)INT_MIN)
                {
                    return t[{idx, last, d, done}] = f(idx + 1, idx, a[idx] - a[last], done, a, t) + f(idx + 1, last, d, done, a, t);
                }
            }
            else
            {

                if ((long long)a[idx] - a[last] <= (long long)INT_MAX && (long long)a[idx] - a[last] >= (long long)INT_MIN && (a[idx] - a[last]) == d)
                {
                    return t[{idx, last, d, done}] = f(idx + 1, idx, d, true, a, t) + f(idx + 1, last, d, done, a, t);
                }
                else
                {
                    return t[{idx, last, d, done}] = f(idx + 1, last, d, done, a, t);
                }
            }
        }
        else
        {
            if ((long long)a[idx] - a[last] <= (long long)INT_MAX && (long long)a[idx] - a[last] >= (long long)INT_MIN && (a[idx] - a[last]) == d)
            {
                return t[{idx, last, d, done}] = f(idx + 1, idx, d, done, a, t) + f(idx + 1, last, d, done, a, t);
            }
            else
            {
                return t[{idx, last, d, done}] = f(idx + 1, last, d, done, a, t);
            }
        }
    }
}

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        map<vector<int>, int> t;
        return f(0, -1, -1, false, nums, t);
    }
};