
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

int f(int curr, int idx,  int k, vvi &a, unordered_map<pair<int,int>, int> &tf){
    if(curr >= k){
        return 0;
    }
    if(idx == a.size()){
        return 1e9;
    }
    if(tf.find({curr, idx}) != tf.end()){
        return tf[{curr, idx}];
    }
    int fuel = a[idx][1];
    int dist = a[idx][0];
    int stop = 1e9;
    if(curr >= dist){
        stop = 1 + f(curr + fuel, idx+1, k, a, tf);
    }
    int dont = f(curr, idx+1, k, a, tf);
    return tf[{curr, idx}]= min(stop, dont);
}   


int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
{
    // Write your code here.
    unordered_map<pair<int,int>, int> tf;
    int ans = f(startFuel, 0, target, stations, tf);
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}

int main(){
    
}