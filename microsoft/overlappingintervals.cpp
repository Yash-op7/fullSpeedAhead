#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define all(x) x.begin(), x.end()

bool func(vi &a, vi &b){
    if(a[1] == b[1]){
        return a[0]<b[0];
    }
    return a[1] < b[1];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n-1);
    int x, y;
    cin>>x;
    for(int i=0;i<n-1;i++){
        cin>>y;
        a[i] = {min(x, y), max(x, y)};
        x = y;
    }
    sort(all(a), func);             // sort based on ending times
    int i = 0;
    int ans = -1;
    while(i<n-1){
        int curr_right = 
    }
}