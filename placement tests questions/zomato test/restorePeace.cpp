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

bool dfs(int src, int dest, vvi &adj, int parent, int &temp){
    if(src == dest){
        temp = 0;
        return true;
    }
    int ans = 0;
    for(int x:adj[src]){
        if(x != parent){
            if(dfs(x, dest, adj, src, temp)){
                temp++;
                return true;
            }
        }
    }
    return false;
}

int totalDistance(int n, int q, vector<vector<int>> &roads, vector<int> &battles){
    // Write your code here.
    vvi adj(n);
    for(const auto x:roads){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    int src = battles[0];
    int ans = 0;
    for(int i=1;i<battles.size();i++){
        int temp = 0;
        dfs(battles[i-1], battles[i], adj, -1, temp);
        cout<<"distance from "<<battles[i-1] << " to "<<battles[i]<<" is: "<<temp<<'\n';
        ans += temp;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vvi edges(n-1, vi(2, 0));
        for(int i=0;i<n-1;i++){
            cin>>edges[i][0]>>edges[i][1];
        }
        vi qq(q);
        for(int i=0;i<q;i++){
            cin>>qq[i];
        }
        cout<<totalDistance(n, q, edges, qq)<<endl;
    }
}