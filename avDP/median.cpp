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

double findMedianSortedArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    int i = 1;
    int ans = 0;
    int j = 1;
    if ((n + m) % 2 == 0)
    {
        int x = (n + m) / 2;
        int y = x + 1;
        int count1 = 0;
        bool last = false;
        while (count1 < x && i <= n && j <= m)
        {
            if (a[i - 1] < b[j - 1])
            {
                i++;
                last = true;
            }
            else
            {
                j++;
                last = false;
            }
            count1++;
        }
        if (count1 == x)
        {
            if (last)
            {
                ans += a[i - 2];
            }
            else
            {
                ans += b[j - 2];
            }
            if (i <= n && j <= m)
            {
                if (a[i - 1] < b[j - 1])
                {
                    ans += a[i - 1];
                }
                else
                {
                    ans += b[j - 1];
                }
            }
            return ans / 2;
        }
        else
        {
            last = false;
            while (count1 < x && i <= n)
            {
                i++;
                last = true;
            }
            while (count1 < x && j <= m)
            {
                j++;
                last = false;
            }
            if (last)
            {
                ans += a[i - 2] + a[i - 1];
            }
            else
            {
                ans += b[j - 2] + b[j - 1];
            }
            return ans / 2;
        }
    }
    else
    {
        i = 0;
        j = 0;
        int n1 = n + m;
        int cnt1 = 0;
        n1 /= 2;
        bool flag = false;
        while (i < n && j < m && cnt1 <= n1)
        {
            if (a[i] < b[j])
            {
                i++;
                flag = true;
            }
            else
            {
                j++;
                flag = false;
            }
            cnt1++;
        }
        if (cnt1 == n1)
        {
            if (flag)
            {
                ans = a[i - 1];
            }
            else
            {
                ans = b[j - 1];
            }
            return ans / 2;
        }
        else
        {
            bool flag = false;
            while (i < n && cnt1 <= n1)
            {
                i++;
                flag = true;
            }
            while (j < m && cnt1 <= n1)
            {
                j++;
                flag = false;
            }
            if (flag)
            {
                ans = a[i - 1];
            }
            else
            {
                ans = b[j - 1];
            }
            return ans / 2;
        }
    }
}
int main(){
    vi a = {1, 3};
    vi b= {2};
    cout<<findMedianSortedArrays(a, b)<<endl;
}