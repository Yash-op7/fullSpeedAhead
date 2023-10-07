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


void flip(vvi &a){
    int n = a.size();
    vvi b(n, vi(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;i++){
            b[n-i-1][n-j-1] = a[i][j];
        }
    }
    a = b;
}

int f(int x, int y, vvi &a){
    int n = a.size();
    if(x == n-1 && y == n-1){
        if(a[x][y] == -1){
            return -100000;
        }
        if(a[x][y] == 1){
            a[x][y] = 0;
            return 1;
        }
        return 0;
    }
    int curr = a[x][y];
    if(curr == -1)
    {
        return -100000;
    }
    int ans = curr;
    a[x][y] = 0;

    int d = -100000 , r = -100000;
    if(x+1 <n)
    {
        d =  f(x+1, y, a);
    }
    if(y + 1 < n){
        r = f(x, y+1, a);
    }
    ans = ans + max(d, r);
    if(ans < 0){
        a[x][y] = curr;
        return -100000;
    }
    return ans;
}

int greedyJeweller(int n, vector<vector<int>> &a) {
    // Write your code here.

    int going = f(0,0, a);
    flip(a);
    int coming = f(0,0, a);
    if(coming < 0 || going <0){
        return 0;
    }
    return coming + going;
}
