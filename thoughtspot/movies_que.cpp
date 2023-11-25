#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n, 0);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans = 0;
    int p = 0, q = 0;
    bool both = false;
    // assume n>=2
    if(a[0] >= 0){
        p = q = a[0];
        both = true;
    }else{
        p = a[0];
        q = 0;
    }
    if(a[1] >= 0){
        p = max(p, q) + a[1];
        q = p;
        both = true;
    }else{
        if(both){
            p += a[1];
            both = false;
        }else{
            q += a[1];
            swap(p, q);
        }
    }
    for(int i=2;i<n;i++){
        if(a[i] >= 0){
            both = true;
            p = max(p, q) + a[i];
            q = p;
        }else{
            if(both){
                p += a[i];
                both = false;
            }else{
                q += a[i];
                swap(p, q);
            }
        }
    }   
    cout<<max(p, q)<<endl;
}