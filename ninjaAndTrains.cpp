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

int dfs(int src, vvi&adj, int x, vb &vis, vi & a){
    vis[src] = true;
    int ans = 1;
    for(const int it:adj[src]){
        if(!vis[it] && a[it] >= x){
            ans += dfs(it, adj, x, vis, a);
        }
    }
    return ans;
}

int getComponentSize(int x, vvi &adj, vi&a){
    int n = a.size();
    vb vis(n, false);
    int ans = 1;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans = max(ans, dfs(i, adj, x, vis, a));
        }
    }
    return ans;
}

int MaxValueOfK(vector<int> &a, vector<int> &U, vector<int> &V, int k)
{
    // Write your code here.
    int n = a.size();
    vvi adj(n);
    int max1 = 0;
    for(int i=0;i<n;i++){
        adj[U[i] -1].push_back(V[i] - 1);
        adj[V[i] -1].push_back(U[i] - 1);
        max1 = max(a[i], max1);
    }

    int ans = 0;
    int l = 1;
    int r = max1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(getComponentSize(mid, adj, a) >= k){
            l = mid+1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    return ans;
}
int main(){
    vvi adj = {
        {1, 2},//0->1 & 2
        {0, 3},// 1 ->0 & 3
        {0},//2 -> 0
        {1}//3->1
        ,{5},
        {4}
    };
    int n = 6;
    vi a = {1,2, 3,4,5,6};
    vb vis(n, false);
    cout<<dfs(5, adj, 1, vis, a);
}