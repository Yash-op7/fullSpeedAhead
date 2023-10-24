#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

vi solve(vi &a){
    priority_queue<int, vi, greater<int>>minHeap;
    priority_queue<int>maxHeap;
    int n = a.size();
    vi ans(n);
    ans[0] = a[0];
    ans[1] = (a[1] + a[0])/2;
    minHeap.push(a[0]);
    minHeap.push(a[1]);
    maxHeap.push(a[1]);
    maxHeap.push(a[0]);
    for(int i=2;i<n;i++){
        if(a[i] < maxHeap.top()){
            minHeap.push(maxHeap.top());
            maxHeap.push(a[i]);
        }
    }



}





int main(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vi ans = solve(a);
    for(int i:ans){
        cout<<i<<' ';
    }
}