#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    int k;
    cin>>k;
    int r = n - n/3 ;
    int l = n/3 -1;
    while(k>0){
            int x1=0;
            int x2=0;
            for(int i=r; i<n;i++){
                if(arr[i]==arr[r]) x1++;
                else break;
            }
            for(int i=l; i>=0; i--){
                if(arr[i]==arr[l]) x2++;
                else break;
            }
            
            if(x1<=x2 && x1<=k){
                for(int i=0; i<x1;i++) arr[r+i]++;
                k = k-x1;
            }
            else if(x2<x1 && x2<=k){
                for(int i=0; i<x2;i++) arr[l-i]--;
                k = k-x2;
            }
            
            else if(x1>k && x2 > k) k =0;
            
        }
            
        
            
        for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        cout<<endl;
        cout<<arr[r]-arr[l]<<endl;
    
    
}