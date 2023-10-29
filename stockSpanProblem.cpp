#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&a){
    int n = a.size();
    stack<int> stk;
    vector<int> ans (n, 0);
    for(int i=n-1;i>=0;i--){
        if(stk.empty() || a[stk.top()] >= a[i]){
            stk.push(i);
        }else{
            while(!stk.empty() && a[stk.top()] > a[i]){
                int curr = stk.top();
                ans[curr] = curr - i + 1;
                stk.pop();
            }
            stk.push(i);
        }
    }
    while(!stk.empty()){
        int curr = stk.top();
        ans[curr] = curr + 1;
        stk.pop();
    }
    for(auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
}


int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    solve(a);

}