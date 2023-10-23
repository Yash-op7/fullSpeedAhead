#include<bits/stdc++.h>
using namespace std;

int f(int idx, bool canTake, vector<int>&a){
    
}

int solve(vector<int>&arr){
    int n =arr.size();
    vector<int> a(100001, 0);
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }
    return f(0, true, a);
}

int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<< solve(a) << '\n';
}
