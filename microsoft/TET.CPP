#include<bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string>a){
    int n = a.size();
    int m = a[0].size();
    vector<string> ans(n+2);
    for(int i=1;i<=n;i++){
        ans[i] = "*"+a[i-1]+"*";
    }
    string temp = "";
    for(int i=0;i<m+2;i++){
        temp+="*";
    }
    ans[0] =temp;
    ans[ans.size()-1] = temp;
    return ans;
}