
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

int minimumIntensity(int A, vvi &B, vi &C, int D, int E){
    vvi adj(A);
    for(const auto x:B){
        adj[x[0] - 1].push_back(x[1] - 1);
        adj[x[1] -1].push_back(x[0] -1);
    }
    vector<bool> has(A, false);
    for(const auto x:C){
        has[x-1] = true;
    }
    vi dist(A, 1e9);
    priority_queue<vi, vvi, greater<vi>>q;
    q.push({0, 0, D-1});        // {currentIntensity, maxIntensity on this path, currentNode}
    dist[D-1] = 0;
    while(!q.empty()){
        vi curr = q.top();
        q.pop();
        int src = curr[2];
        int intensity = curr[0];
        int maxIntensity = curr[1];
        if(src == E-1){
            return max(intensity, maxIntensity);
        }
        if(has[src]){
            maxIntensity = max(maxIntensity, intensity);
            intensity = 0;
        }
        for(const auto next:adj[src]){
            if(dist[next] > intensity + 1){
                dist[next] = intensity + 1;
                q.push({intensity+1, maxIntensity, next});
            }
        }
    }
    return -1;
}

int main(){
    int n, m;
    cin>>n>>m;
    vvi B(m, vi(2, 0));
    for(int i=0;i<m;i++){
        cin>>B[i][0]>>B[i][1];
    }
    int k;
    cin>>k;
    vi C(k);
    for(int i=0;i<k;i++){
        cin>>C[i];
    }
    int D,E;
    cin>>D>>E;
    cout<<minimumIntensity(n, B, C, D, E)<<'\n';
}

/*
sample test case given in the question was:
6 5
1 2
2 3
3 4
4 5
5 6
2
1 3
1 6
*/