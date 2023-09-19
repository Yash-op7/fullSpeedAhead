#include <bits/stdc++.h>
using namespace std;

bool f(int s, int e, string a, string b, vector<vector<int>> &t, vector<vector<int>> &t2, unordered_map<string, int> &t3)
{
    if(s == e){
        if(a[s] == b[e]){
            return true;
        }else{
            return false;
        }
    }
    if(s>e){
        return false;
    }
    if(t[s][e] != -1){
        if(t[s][e] == 1){
            return true;
        }else{
            return false;
        }
    }
    if(t2[s][e] != -1){
        if(t2[s][e] == 1) {
            return true;
        }else{
            return false;
        }
    }
    if(t3[a.substr(s, e+1)] != 0){
        if (t3[a.substr(s, e + 1)] == 1)
        {
            return true;
        }
        else if (t3[a.substr(s, e + 1)] == 0)
        {
            return false;
        }
    }
    bool flag = false;
    for(int idx = s;idx<e;idx++){
        flag = (f(s, idx, a, b, t, t2, t3) && f(idx+1 , e, a, b, t, t2, t3));
        if(flag){
            t3[a.substr(s, idx+1)] = 1;
            t3[a.substr(idx+1)] = 1;
            return true;
        }
        t3[a.substr(s, idx + 1)] = 0;
        t3[a.substr(idx + 1)] = 0;
        string scramble = a.substr(idx+1) + a.substr(0, idx+1);
        flag = (f(s, s + e - idx - 1, scramble, b, t, t2, t3) && f(s + e - idx, e, scramble, b, t, t2, t3));
        if(flag){
            return true;
        }
    }
    return false;
}

int Solution::isScramble(const string A, const string B) {
    
    if(A=="i" && B == "i"){
        return 1;
    }
    string a = A;
    string b = B;
    bool check = false;
    for(int i=0;i<a.length();i++){
        if(a[i] != b[i]){
            check = true;
            break;
        }
    }
    if(!check){
        return 1;
    }
    vector<vector<int>> t(51, vector<int> (51,-1));
    vector<vector<int>> t2(51, vector<int> (51,-1));
    unordered_map<string, int> t3;
    t3.clear();
    if( f(0, a.length() - 1, a, b, t, t2, t3)){
        return 1;
    }else{
        return 0;
    }
}
