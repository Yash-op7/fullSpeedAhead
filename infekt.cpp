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


int minMalwareSpread(vector<vector<int>>& graph, vector<int>& malware)
{
	// Write your code here
	unordered_map<int , bool> isMalware;
	for(const auto x:malware){
		isMalware[x] = true;
	}
	int n = graph.size();
	int ans = 0;
	int maxCount = 0;
	for(int i=0;i<malware.size();i++){
		int currCount = 0;
		int x = malware[i];
		vb vis(n, false);

		for(int j=0;j<n;j++){
			// for the ith malware go to each edge from it
			currCount = 0;
            bool infected = false;
            int branchCnt = 0;
			if(graph[x][j] == 1){
				queue<int> q;
				if(!vis[j]){
					q.push(j);
					vis[j] = true;
                    if (isMalware[j])
                        {
                            infected = true;
                            break;
                        }
                    branchCnt++;
					while(!q.empty()){
						int top = q.front();
						q.pop();
						for(int z=0;z<n;z++){
							if(graph[top][z] == 1 && !vis[z]){
								q.push(z);
								vis[z] = true;
                                if (isMalware[z])
                                {
                                    infected=true;
									break;
                                }
                                branchCnt++;
							}
						}
					}
				}
			}
            if (!infected)
            {
                currCount += branchCnt;
            }
		}
        if (currCount > maxCount)
        {
            ans = i;
            maxCount = currCount;
        }
    }
	return ans;
}