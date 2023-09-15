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
  public:
      void from1(vi &from, int n)
      {
          if (n == 0)
          {
              cout << n << " ";
              return;
          }
          cout << from[n] << " ";
          from1(from, from[n]);;
      }
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // dijkstra wt, dest
        pq<vi> pq1;
        vvi adj[n];
        for(const auto &x:edges){
            adj[x[0]-1].push_back({x[1]-1, x[2]});
            adj[x[1]-1].push_back({x[0]-1, x[2]});
        }
        vi dist(n, INT_MAX);
        vi from(n, -1);
        int src= 0;
        dist[src] = 0;
        pq1.push({0, src, -1});

        while(!pq1.empty()){
            vi top = pq1.top();
            pq1.pop();
            int currDist = top[0];
            int currNode = top[1];
            int currParent = top[2];
            from[currNode] = currParent;
            for(auto dest:adj[currNode]){
                // dest = {destNode, wt}
                if(dist[dest[0]] > currDist + dest[1]){
                    dist[dest[0]] = currDist + dest[1];
                    pq1.push({dist[dest[0]], dest[0], currNode});
                }
            }
        }
        vi ans;
        int currNode = n-1;
        while(currNode != -1){
            ans.push_back(currNode+1);
            currNode = from[currNode];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};