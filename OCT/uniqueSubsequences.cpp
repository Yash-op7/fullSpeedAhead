#include<bits/stdc++.h>
using namespace std;

int f(int idx, char last, string &str, vector<vector<int>>&t){
    if(idx == str.length()){
        return 0;
    }
    if(last == '$'){
        return max(f(idx+1, last, str, t), 1 + f(idx+1, str[idx], str, t));
    }else{
        if(t[idx][last-'a'] != -1){
            return t[idx][last-'a'];
        }
        if(str[idx] == last){
            return t[idx][last - 'a'] = f(idx + 1, last, str, t);
        }else{
            return t[idx][last - 'a'] = max(f(idx + 1, last, str, t), 1 + f(idx + 1, str[idx], str, t));
        }
    }
}

int solve(string &str){
    vector<vector<int>>t(str.length(), vector<int>(26, -1));
    return f(0, '$', str, t);
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        cout<<solve(str)<<'\n';
    }
}