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
const int MOD = 1e8;

int f(int R, int B, int last, int taken, int X, int Y, vector<vector<vector<vector<int>>>> &t){
    if(R+B == 0){
        return 1;
    }
    if(last == -1){
        int red = 0;
        if(X>0 && R>0 && taken < X){
            // can take red;
            red = f(R-1, B, 1, 1,X, Y, t)%MOD;
        }
        int blue = 0;
        if(Y>0 && B>0 && taken<Y){
            blue = f(R, B-1 ,2, 1, X, Y, t)%MOD;
        }
        return (red+blue)%MOD;
    }    
    else{
        if(t[R][B][last-1][taken] != -1){
            // return t[R][B][last-1][taken];
        }
        int red =0;
        int blue = 0;
        if(last == 1){
            if(taken < X && R > 0){
                red += f(R-1, B, 1, taken+1, X, Y, t)%MOD;
            }
            if(B>0 && Y>0){
                red+= f(R, B-1, 2, 1, X, Y, t)%MOD;
            }
            return t[R][B][last-1][taken]= red%MOD;
        }else{
            if(taken < Y && B > 0){
                blue += f(R, B-1, 2, taken+1, X, Y, t)%MOD;
            }
            if(X>0 && R>0){
                blue += f(R-1, B, 1, 1, X, Y, t)%MOD;
            }
            return t[R][B][last-1][taken]= blue%MOD;
        }
    }
}

int beautifulCity(int N, int R, int B, int X, int Y)
{
    // Write your code here.   
    // vector<vector<vector<vector<int>>>> t(101, 101, 2, 11)
    vector<vector<vector<vector<int>>>> t(101,vector<vector<vector<int>>>(101, vector<vector<int>>(2, vector<int>(11, -1))));
    f(R, B, -1, 0, X, Y, t);
}