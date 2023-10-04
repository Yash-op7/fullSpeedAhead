#include <bits/stdc++.h> 
using namespace std;
#define vi vector<int>
int findToll(int n, int m, vector<vector<int>> &time, vector<vector<int>> &toll) 
{
    // Write your code here	
    priority_queue<vi, vector<vi>, greater<vi>> q;
    vi dist(n, 1e9);
    int src = 0, dest = n-1;
    dist[src] = 0;
    
    q.push({dist[src], 0, src});
    while(!q.empty()){
        int currTime = q.top()[1];
        int currDist = q.top()[0];
        int currNode = q.top()[2];
        q.pop();
        if(currNode == dest){
            if(currTime <= m){
                return currDist;
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i] > dist[currNode] + toll[currNode][i]){
                dist[i] = dist[currNode] + toll[currNode][i];
                q.push({dist[i], currTime + time[currNode][i], i});
            }
        }
    }
    return -1;
}