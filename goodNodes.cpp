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

bool dfs(int src, vi &a, vb &vis, vb &vis2){
    vis2[src] = true;
    if(src == 0){
        return true;
    }
    int next = a[src];
    if(!vis2[next] && !vis[next]){
        if(dfs(next, a, vis, vis2)){
            vis[src] = true;
            return true;
        }else{
            return false;
        }
    }else if(vis[next]){
        vis[src]=true;
        return true;
    }else if(vis2[next]){
        return false;
    }
    return false;
}

int solve(vector<int> &A) {
    int n= A.size();
    vb vis(n, false);
    for(int i=0;i<n;i++){
        A[i]--;
    }
    int ans = 0;
    vis[0] = true;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vb vis2(n, false);
            if(dfs(i, A, vis, vis2)){
                vis[i] = true;
            }else{
                ans++;
                for(int j=0;j<n;j++){
                    if(vis2[j]){
                        vis[j] = true;
                    }
                }
            }
        }
    }
    
    return ans;

}
