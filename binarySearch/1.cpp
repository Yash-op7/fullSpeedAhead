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

bool check(ll k, vi &time, int n)
{
    int m = time.size();
    int x = 0;
    ll temp = k;
    int i =0;
    pq<int> p;
    p.p
    while(i<m){
        if(temp>=time[i]){
            temp -= time[i];
            i++;
            if(i == m){
                x++;
                break;
            }
        }else{
            if(temp == k){
                return false;
            }
            x++;
            temp = k;
        }
    }
    if (x <= n)
    {
        return true;
    }
    return false;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    ll sum = 0;
    ll min1 = INT_MAX;
    for (const ll x : time)
    {
        sum += x;
        min1 = min(x, min1);
    }

    ll s = min1;
    ll e = sum;
    ll ans = sum;
    while (s <= e)
    {
        ll mid = s + ((e - s) / 2);
        if (check(mid, time, n))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}