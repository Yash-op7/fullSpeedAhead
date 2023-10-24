#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &temp){
	int n = temp.size();
	vector<int> ans(n);
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i=0; i<n; i++){
		if(maxHeap.empty() || maxHeap.top()>= temp[i]){
			maxHeap.push(temp[i]);
		}
		else{
			minHeap.push(temp[i]);
		}
		//balancing the heaps
		if(minHeap.size() > maxHeap.size()){
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		else if(maxHeap.size() > minHeap.size()+1){
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		//calculating median.
		if(i%2==0){
			ans[i] = maxHeap.top();
		}
		else{
			ans[i] = (maxHeap.top()+minHeap.top())/2;
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> temp(n);
	for(int i=0; i<n; i++) cin>>temp[i];
	vector<int> ans = solve(temp);
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}