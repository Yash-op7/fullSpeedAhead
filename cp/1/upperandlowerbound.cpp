#include<bits/stdc++.h>
using namespace std;

int lowerBound1(vector<int> &a, int key){
    int n = a.size();
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        int x = a[mid];
        cout<<"mid is "<<x<<endl;
        if(key < x){
            ans = mid;
            cout<<"curr ans is "<<a[ans]<<endl;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> a = { 1, 3, 5, 6 ,8, 15, 19};
    int n = a.size();
    int key = 5;
    for(int x:a){
        cout<<x<<" ";
    }cout<<'\n';
    int ans = lowerBound1(a, key)+1;
    cout<<"lower bound of "<<key<<" is at "<<ans<<" \n";
    }