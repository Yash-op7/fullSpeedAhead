#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;


vector<int> makeArray(int n, vector<vector<int>> &a)
{
    // Write your code here
    int l = INT_MAX;
    int r = -1;
    for(const auto x:a){
        for(const auto y:x){
            r = max(y, r);
        }
    }
    int y = r;
    vvi adj(y+1);
    vi indegree(y+1, -1);
    for(const vi curr:a){
        for(int i=1;i<curr.size();i++){
            int from = curr[i-1];
            int to = curr[i];
            if(indegree[to] == -1){
                indegree[to] = 0;
            }
            if(indegree[from] == -1){
                indegree[from] = 0;
            }
            adj[from].push_back(to);
            indegree[to]++;
        }
    }
    vi ans;
    queue<int>q;
    for(int i=0;i<=y;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(const auto nex:adj[front]){
            indegree[nex]--;
            if(indegree[nex] == 0){
                q.push(nex);
            }
        }
    }
    // reverse(all(ans));
    return ans;
}


int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin >> n;
        vvi a(n);
        string temp;
        getline(cin, temp);
        for(int i=0;i<n;i++){
            string input;
            getline(cin, input);
            std::vector<int> result;
            std::istringstream iss(input);
            int num;
            while (iss >> num)
            {
                result.push_back(num);
            }
            // a[i] = __result_of_success
            a[i] = result;
        }
        vi ans = makeArray(n, a);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
}