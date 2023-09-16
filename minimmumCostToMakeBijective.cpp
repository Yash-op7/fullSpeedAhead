#include <bits/stdc++.h> 
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

int f(int idx, int mask, vvi &cost ,vvi&t){
	int n = cost.size();
	int m= cost[0].size();

	if(idx == n){
		if( (mask == (1<<m) - 1) ){
			return 0;
		}
		else{
			
			return 1e9;
		}
	}
	if(t[idx][mask]!=-1){
		// return t[idx][mask];
	}
	int connect = INT_MAX;
	int temp = mask;
	for(int i=0;i<m;i++){
		mask = (mask | (1<<i));
		connect = min(
			connect,
			cost[idx][i] + f(idx+1, mask, cost, t)
		);
		mask = temp;
	}
	return t[idx][mask]= connect;
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
		return f(idx, mask, cost, t);
	}else{
		vvi c(m, vector<int>(n ,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				c[j][i] = cost[i][j];
			}
		}
		vvi t(m, vi(1024, -1));
		return f(idx, mask, c, t);
	}

}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vvi costs(n, vi(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>costs[i][j];
            }
        }
        cout<<connectTwoGroups(costs)<<endl;
    }
}