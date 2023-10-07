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

bool f(int s, int e, const string &A, const string &B){
    if(s == e){
        if(A[s] == B[s]){
            return true;
        }else{
            return false;
        }
    }
    int n = A.size();
    for(int i=0;i<n-1;i++){
        bool left = f(s, i, A, B);
        bool right = f(i+1, e, A, B);
        bool lr = f()
    }
}

int isScramble(const string A, const string B)
{
    return f(0, A.length() - 1, A, B);
}
