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

string alienOrder(vector<string> &arr, int n)
{	
	// Write your code here	
	unordered_map<char, string> order;
	vector<int> indegree(26, -1);
	for(int i=1;i<arr.size();i++){
		string one = arr[i-1];
		string two = arr[i];
		for(int j=0;j<min(one.length(), two.length());j++){
			if(one[j] != two[j]){
				if(indegree[one[j] - 'a'] == -1){
					indegree[one[j]-'a'] = 0;
				}
                if(indegree[two[j] - 'a'] == -1){
                    indegree[two[j] -'a'] = 0;
                }
				order[two[j]] += one[j];
				indegree[one[j] - 'a']++;
				break;
			}
		}
	}
    for(int i=0;i<n;i++){
        char c1 = i + 'a';
        sort(all(order[c1]));
    }
	string ans = "";
	queue<char> q;
	for(int i=0;i<26;i++){
		if(indegree[i] == 0){
			q.push((char)(i + 'a'));
		}
	}
	while(!q.empty()){
		char front = q.front();
		q.pop();
		ans += front;
		for(int i=0;i<order[front].length();i++){
			char curr = order[front][i];
			indegree[curr - 'a']--;
			if(indegree[curr-'a'] == 0){
				q.push(curr);
			}
		}
	}
	reverse(all(ans));
	return ans;

}

int main(){
    int tt;
    cin>>tt;
    while(tt--){

        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << alienOrder(a, n) << endl;
    }

}