// 22:33
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

class Solution {

    bool canColor(int src, int curr, vi adj[], vi &color){
        if(color[src] != -1 && color[src] != curr){
            return false;
        }
        if(color[src] == curr){
            return true;
        }
        color[src] = curr;
        for(auto x:adj[src]){
            if(color[x] == -1){
                if(!canColor(x, curr xor 1, adj, color)){
                    return false;
                }
            }
        }
        return true;
    }

public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here

        // vb vis(V, false);
        vi color(V, -1);
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(!canColor(i, 0, adj, color)){
                    return false;
                }
            }
        }
        return true;

	}

};