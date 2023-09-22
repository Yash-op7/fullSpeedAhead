#include <bits/stdc++.h>
using namespace std;

int f(int idx, vector<int> &a)
{
    int n = a.size();
    if (idx == -1)
    {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                sum1 += a[i];
            }
            else
            {
                sum2 += a[i];
            }
        }
        return max(sum1, sum2);
    }
    else
    {
        int sum1 = 0;
        int sum2 = 0;
        int val = a[idx];
        for (int i = 0; i < n; i += 2)
        {
            if (i == idx)
            {
                continue;
            }
            sum1 += a[i];
        }
        for (int i = 1; i < n; i += 2)
        {
            if (i == idx)
            {
                continue;
            }
            sum2 += a[i];
        }
        return val + min(sum1, sum2);
    }
}

int getMaxFruits(vector<int> &a, int n)
{
    // Write your code here
    n = a.size();
    if (n % 2 == 0)
    {
        return f(-1, a);
    }
    else
    {
        return max(f(0, a), f(n - 1, a));
    }
}