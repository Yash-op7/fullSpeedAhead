// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<bits/stdc++.h>
using namespace std;    
#define vi vector<int>
vi dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
int solution(vector< vector<int> > &A) {
    // Implement your solution here
    int n = A.size(), m = A[0].size();
    int ans = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;
    }
    for(int i2=1;i2<9;i2++){
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && ((A[i][j] == i2) || (A[i][j] == i2+1))){
                    queue<vi>q;
                    q.push({i, j});
                    int sz = 0;
                    while(!q.empty()){
                        vi curr = q.front();q.pop();
                        int x= curr[0],y= curr[1];
                        for(int j=0;j<4;j++){
                            int tx = x + dx[j], ty = y +dy[j];
                            if(tx < n && tx >= 0 && ty < m && ty >= 0 && !vis[tx][ty]){
                                if((A[tx][ty] == i2) || (A[tx][ty] == i2+1)){
                                    q.push({tx, ty});
                                    sz++;
                                    vis[tx][ty]=true;
                                }
                            }
                        }
                    }
                    ans = max(ans, sz);
                }
            }
        }

    }
    cout<<ans;
    return ans;
}