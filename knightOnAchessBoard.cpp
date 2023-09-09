
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pq priority_queue
#define ll long long
#define MOD 1e9 + 7
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    if(!(C<A && C>=0 && D<B && D>=0 && E>=0 && E< A && F>=0 && F<B)){
        return -1;
    }
    vector<vb> vis(A, vb(B, false));
    queue<vi> q;
    q.push({C, D});
    q.push(nullptr);
    int dist = 0;
    vis[C][D] = true;
}
