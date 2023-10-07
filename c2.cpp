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

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin>>n>>k;
        vi a(n, 0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vb vis(n, false);
        unordered_map<int, vi> loc;
        for(int i=0;i<n;i++){
            loc[a[i]].push_back(i);
        }
        sort(all(a));
        int last = n - 1;
        int first = 0;
        vi ans(k, 0);
        for(int i=0;i<n;i++){
            if(ans[a[i]-1] == 0){
                int curr = a[i];
                for(int j=first;j<n;j++){
                    if(!vis[j]){
                        first = j;
                        break;
                    }
                }
                for(int j=last;j>=0;j--){
                    if(!vis[j]){
                        last = j;
                        break;
                    }
                }
                int currAns = last - first + 1;
                ans[curr-1] = 2*currAns;
                vi currLocations = loc[curr];
                for(auto j:currLocations){
                    vis[j] = true;
                }
            }
        }
        for(int i=0;i<k;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}