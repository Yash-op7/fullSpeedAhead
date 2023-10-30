#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    int start =0;
    int end = arr[n-1] - arr[0];
    while(start<=end){
        int mid = (start+end)/2;
        vector<int> house(n,0);
        vector<int> res(arr[n-1]+1,0);
        int count =0;
        for(int i=1; i<=arr[n-1]; i++){
            for(int j=0; j<n;j++){
                if(house[j] == 0 && abs(arr[j] - i)<= mid ){
                    house[j] =1;
                    if(res[i] == 0){
                        count++;
                        res[i] =1;
                    }
                }
            }
        }
        if(count == k){
            cout<<mid;
            break;
        }
        if(count > k) end = mid;
        
        if(count < k) start = mid;
        
    }
}