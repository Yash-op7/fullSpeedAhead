// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<bits/stdc++.h>
using namespace std;
#define vb vector<bool>
#define vvb vector<vb>
#define vi vector<int>

vi dx = {1, -1, 0, 0};
vi dy ={0, 0, 1, -1};

int dfs(int x, int y, vvb&visited, vvb &grid){
    int n = grid.size(), m = grid[0].size();
    if(x == n-1 && y == m-1){
        return 0;
    }
    int ret = 1e9;
    for(int i=0;i<4;i++){
        int x2  = x+ dx[i];
        int y2 = y + dy[i];
        if(x2 < n && x2 >=0 && y2<m && y2>=0 && grid[x2][y2] && !visited[x2][y2]){
            visited[x2][y2] = true;
            ret = min(ret ,(1+ dfs(x2, y2, visited, grid)));
            visited[x2][y2] = false;
        }
    }
    return ret;

}

int solution(int n, int m, vector<int> &X1, vector<int> &Y1, vector<int> &X2, vector<int> &Y2) {
    // Implement your solution here
    int N = X1.size();
    vvb grid(n, vector<bool>(m, true));
    for(int i=0;i<N;i++){
        for(int x=X1[i];x<=X2[i];x++){
            for(int y=Y1[i];y<=Y2[i];y++){
                grid[x][y]=false;
            }
        }
    } 
    vvb visited(n, vector<bool>(m, false));
    int ans = dfs(0, 0, visited, grid);
    if(ans >= 1e9){
        return -1;
    }
    return ans;

}
int main{
}