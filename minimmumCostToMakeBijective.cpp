#include <bits/stdc++.h> 
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

int f(int x, int y, int mask, vvi &cost, vvi&t){
    int n = cost.size();
    int m= cost[0].size();

    if(x == n){
        if(mask + 1 == (1<<m)){
            return 0;
        }
        return 1e9;
    }
    if(t[x][mask] != -1){
        return t[x][mask];
    }
    int connect = INT_MAX;
    int temp = mask;
    for(int i=y;i<m;i++){
        mask = (1<<i)|mask;
        connect = min(
            connect,
            cost[x][i] + min(f(x+1, 0, mask, cost, t), f(x, i+1, mask, cost, t))
        );
        mask = temp;
    }
    return t[x][mask] = connect;
}

int connectTwoGroups(vector<vector<int>> &cost)
{
	//	Write your code here.
	int n = cost.size();
	int m = cost[0].size();
	int mask = 0;
	int idx = 0;
	if(n>=m){
		vvi t(n, vi(1024, -1));
		return f(idx, 0, mask, costf, t);
	}else{
		vvi c(m, vector<int>(n ,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				c[j][i] = cost[i][j];
			}
		}
		vvi t(m, vi(1024, -1));
		return f(idx, 0, mask, c, t);
	}

}
