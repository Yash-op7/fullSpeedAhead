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

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        string s;
        cin>>s;
        int cnt = 0;
        for(int i=0;i<3;i++){
            if(s[i] == 'a'){
                if(i != 0){
                    cnt++;
                }
            }else if(s[i] == 'b'){
                if(i != 1){
                    cnt ++;
                }
            }else{
                if(i!=2){
                    cnt++;
                }
            }
        }
        if(cnt == 3){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}