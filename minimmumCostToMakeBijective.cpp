#include <bits/stdc++.h> 
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

int f(int x, int y, int mask, vvi &cost, vvi&t){
    int n = cost.size();
    int m= cost[0].size();
    
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
		return f(idx, 0, mask, cost, t);
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
