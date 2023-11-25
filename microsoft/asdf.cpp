// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<bits/stdc++.h>
#define vb vector<bool>
#define vvb vector<vb>
#define vi vector<int>
vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};
int solution(vector< vector<int> > &A) {
    // Implement your solution here
    int n = A.size(), m = A[0].size();
    int ans = 1;
    for(int currValue=1;currValue<9;currValue++){
        vvb visited(n, vb(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && ((A[i][j] == currValue) || (A[i][j] == currValue+1))){
                    queue<vi>q;
                    q.push({i, j});
                    int currAns = 0;
                    while(!q.empty()){
                        vi curr = q.front();
                        int x= curr[0],y= curr[1];
                        for(int j=0;j<4;j++){
                            int tx = x + dx[j], ty = y +dy[j];
                            if(tx  < n && tx >= 0 && ty < m && ty >= 0 && !visited[tx][ty]){
                                if((A[tx][ty] == currValue) || (A[tx][ty] == currValue+1)){
                                    q.push({tx, ty});
                                    currAns++;
                                    visited[tx][ty]=true;
                                }
                            }
                        }
                        q.pop();
                    }
                    ans = max(ans, currAns);
                }
            }
        }

    }
    return ans;
}