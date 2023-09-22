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
        for(int j=0;j<n;j++){
            b[n-i-1][n-j-1] = a[i][j];
        }
    }
    a = b;
}

int f(int x, int y, vvi &a, vvi &t){
    int n = a.size();
    if(x == n-1 && y == n-1){
        if(a[x][y] == -1){
            return -100000;
        }
        if(a[x][y] == 1){
            return  1;
        }
        return 0;
    }
    if(t[x][y] != -1){
        return t[x][y];
    }
    int curr = a[x][y];
    if(curr== -1){
        return t[x][y] = -100000;
    }
    int ans = a[x][y];
    int d = -1e5;
    int r = -1e5;

    if(x+1<n){
        d = f(x+1, y, a, t);
    }
    if(y+1< n){
        r = f(x, y+1, a, t);
    }
    return t[x][y] = ans + max(d, r);
}
void updatePath(int x,int y, vvi &a, vvi &t){
    int n = a.size();
    int d = -1e5;
    int r = -1e5;
    if(x == n-1 && y == n-1){
        a[x][y] = 0;
        return;
    }
    
    if(x+1<n){
        d = t[x+1][y];
    }
    if(y + 1<n){
        r = t[x][y+1];
    }
    a[x][y] = 0;
    if(d > r){
        updatePath(x+1, y, a, t);
    }else{
        updatePath(x, y+1, a, t);
    }
}

int greedyJeweller(int n, vector<vector<int>> &a) {
    // Write your code here.
    vvi t(n, vi(n, -1));
    int going = f(0, 0, a, t);
    if(going<0){
        return 0;
    }
    updatePath(0,0,a,t);
    flip(a);
    t = vvi(n, vi(n, -1));
    int coming = f(0,0, a, t);
    return coming + going;
}
