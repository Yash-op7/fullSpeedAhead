#include <bits/stdc++.h> 
#define vi vector<int>
#define vvi vector<vi>


void bfs(int src, int v, int k, vi &cnt, vvi &adj){
    vector<bool> vis(v, false);
    queue<int> q;
    q.push(src);
    q.push(-1);
    int spread = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(front != -1){
            if(spread < 2 + k){
                cnt[front]++;
            }
            for(auto adjacent:adj[front]){
                if(!vis[adjacent]){
                    vis[adjacent] = true;
                    q.push(adjacent);
                }
            }
        }else{
            spread ++;
            if(!q.empty()){
                q.push(-1);
            }
        }
    }
}

int nodesWithinKDistance( vector<vector<int>> &edges, int v, vector<int> &marked, int m, int k){
    // Write your code here
    vvi adj(v);
    for(const auto &x:edges){
        adj[x[0]-1].push_back(x[1]-1);
        adj[x[1]-1].push_back(x[0]-1);
    }
    vi cnt(v, 0);
    for(auto x:marked){
        bfs(x, v, k, cnt, adj);
    }
    return count(cnt.begin(), cnt.end(), m);

}