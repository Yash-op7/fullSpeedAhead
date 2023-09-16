#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int c = 0;
int f(int idx)
{
    c++;
    if (idx == 9)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        ans += f(idx + 1);
    }
    return ans;
}

int main()
{
    cout<<f(0)<<endl;
    cout<<c<<endl;
}