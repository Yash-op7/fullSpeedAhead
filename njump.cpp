
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

int canReachEnd(int idx, set<int>&h1, vi &a, unordered_map<int, vi>&locs){
    // odds
    if(idx == a.size() - 1){
        return 1;
    }
    if(h1.empty()){
        return 0;
    }
    bool flag = true;
    int loc = -1;

    while(flag){
        auto it = h1.lower_bound(a[idx]);
        if(it == h1.end()){
            flag= false;
            break;
        }
        int val = *it;
        vi temp = locs[val];
        while(true){
            if(temp.size() == 0){
                h1.erase(it);
                // flag = false;
                break;
            }else{
                if((temp.back()<=idx) || ((temp.back() - idx)%2 == 0)){
                    temp.pop_back();
                }else{
                    flag = false;
                    loc = temp.back();
                    temp.pop_back();
                    break;
                }
            }
        }
    }
    if(loc == -1){
        return 0;
    }else{
        return canReachEnd(loc, h1, a, locs);
    }
}


int ninjaJump(vector<int> &x,int n)
{
    // Write your code here.
    set<int> h1;
    unordered_map<int, vi> locs;
    for(int i=0;i<n;i++){
        h1.insert(x[n-1-i]);
        locs[x[n-i-1]].push_back(n-i-1);
    }
    int ans = 0;
    unordered_map<int, vi> locs2 = locs;
    unordered_map<int, vi> locs3 = locs;

    set<int> h2 = h1;
    set<int> h3 = h1;
    for(int i=0;i<n;i++){
        int currResult = canReachEnd(i, h2, x, locs2);
        ans += currResult;
        locs2 = locs;
        locs3 = locs;
        h3 = h1;
        h2 = h1;
    }
    return ans-1;
    
}











