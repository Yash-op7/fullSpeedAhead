#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod = 1e9 + 7;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < n-1; i++){
        int a;
        cin >> a;
        v.push_back({a, 0});
    }
    for (int i = 0;i<m-1; i++){
        int a;
        cin >> a;
        v.push_back({a, 1});
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    
    for(auto &a:v){
        if(a.second==0){
            sum += (a.first * m);
            sum %= mod;
            n--;
        }else{
            sum += (a.first * n);
            sum %= mod;
            m--;
        }
    }
    cout << sum << endl;
}