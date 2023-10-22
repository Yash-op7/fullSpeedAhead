#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int>mp;
    mp[0]=0;
    mp[1]=10;
    mp[2]= 3;
    mp[3] = -1;
    cout<<mp.rbegin()->first;
}