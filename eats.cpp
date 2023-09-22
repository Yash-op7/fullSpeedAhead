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

int f(int s, int e, vi &a){
    if(s>=e){
        return 0;
    }
    int pick1 = a[s] + max(f(s+2, e, a), f(s+1, e-1, a));
    int pickn = a[e] + max(f(s+1, e-1, a) , f(s, e-2, a));
    return max(pick1, pickn);
}

int getMaxFruits(vector<int> &a, int n)
{
    // Write your code here
    return f(0, n-1, a);
}