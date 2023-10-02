#include<bits/stdc++.h>
using namespace std;

int f(int n){
    queue<int> q;
    q.push(n);
    q.push(-1);
    int ans = n;
    int spread = 0;
    while(!q.empty()){
        int x = q.front();
        if(spread>=4){
            return 4;
        }
        q.pop();
        if(x == 0){
            return spread;
        }
        if(x == -1){
            if(!q.empty()){
                q.push(-1);
                spread++;
            }
        }else{
            for(int i=1;i*i<=x;i++){
                q.push(x-i*i);
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}