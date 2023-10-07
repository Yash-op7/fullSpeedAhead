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
        int n,x;
        cin>>n>>x;
        vi a(n, 0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        unordered_map<int, int> store;
        for(int currH:a){
            store[currH]++;
        }
        pq<vi, vvi, greater<vi>>q;
        for(auto edge:store){
            q.push({edge.first ,edge.second});  //h and cnt
        }
        bool flag=  false;
        int h = 0;
        while(x>0 && !q.empty()){
            vi curr = q.top();
            q.pop();
            int smallest = curr[0];
            int cnt = curr[1];
            if(h == 0){
                if(x >= smallest*n){
                    x -= smallest*n;
                    h = smallest;
                }else{
                    int capacity = x/n;
                    cout<<capacity<<'\n';
                    flag = true;
                    break;
                }
            }else{
                if(q.empty()){
                    
                }
                int reqd = smallest*cnt;
            }
        }
        if(flag){
            continue;
        }
    }
}