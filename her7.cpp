#include <bits/stdc++.h>
using namespace std;


int f(int idx, vector<int>&a){
    return max(f(idx+2, a) + a[idx], f(idx+1, a));
}

int solve(vector<int> &arr)
{
    int n = arr.size();
    vector<int> a(1e5 + 1, 0);
    for (int i = 0; i < n; i++)
    {
        a[arr[i]]++;
    }
    int curr, prev, prev2;
    prev = a[1];
    prev2 = 0;
    for (int i = 2; i <= 1e5; i++)
    {
        curr = max(i * a[i] + prev2, prev);
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve(a) << '\n';
    }
}
