Copy
#include <bits/stdc++.h>
    using namespace std;

int f(int n, vector<int> &t)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        return n;
    }
    if (t[n - 1] != -1)
    {
        return t[n - 1];
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, f(n - i * i, t) + 1);
    }
    return t[n - 1] = ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> t(n, -1);
    cout << f(n, t) << endl;
}