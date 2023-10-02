#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>



int f(int x, int y, int b, vector<vector<char>> &maze, vector<vb>&vis){
    if(maze[x][y] == 'G'){
        return 0;
    }
    
}

int main(){
    int n,m,b;
    cin>>n>>m>>b;
    vector<vector<char>>maze(n, vector<char>(m, '.'));
    int x=-1;int y=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            if(maze[i][j] == 'S'){
                x = i;
                y = j;
            }
        }
    }
    vector<vb> vis(n, vb(m, false));
    return f(x, y, b, maze, vis);
}