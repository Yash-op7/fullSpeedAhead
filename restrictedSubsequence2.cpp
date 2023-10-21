#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>


#define vvi vector<vi>

int f(int idx, int timeReq, vi &cost, vi &time, vector<vvi> &t){
    cout<<idx<<' '<<timeReq<<'\n';
    if(timeReq >= cost.size()-idx){
        cout<<timeReq<<' '<<(cost.size()-idx)<<" breaking\n";
        return 0;
    }
    if(idx == cost.size()){
        if(timeReq >= 0){
            return 0;
        }
        return 1e9;
    }
    bool flag = true;
    if(timeReq <0){
        flag = false;
    }
    if(t[idx][abs(timeReq)][flag] != -1){
        return t[idx][abs(timeReq)][flag];
    }
    
    int notTake = f(idx+1, timeReq - 1, cost, time, t);
    if(timeReq >=500){
        return t[idx][abs(timeReq)][flag]= notTake;
    }
    int take = cost[idx] + f(idx+1, min(timeReq + time[idx], 500), cost, time, t);
    return t[idx][abs(timeReq)][flag]= min(take, notTake);
}

int paintWalls(vector<int> &cost, vector<int> &time)
{
    vector<vvi> t(cost.size(), vvi(501, vi(2, -1)));
    return f(0, 0, cost, time, t);
}

int main(){
    vi cost = {1, 2, 3,2};
    vi time = {1, 2, 3,2};
    cout<<paintWalls(cost, time)<<endl;

}