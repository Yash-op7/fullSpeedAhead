
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

bool func(vi &a, vi&b){
    return a[0] < b[0];
}

bool check(int x, vi &a, int k, int m){
    int ans = 0;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i] <= x){
            int currFlowerCount=1;
            i++;
            while(currFlowerCount < k && i < n){
                if(a[i] > x){
                    break;
                }else{
                    currFlowerCount++;
                    i++;
                }
            }
            if(currFlowerCount == k){
                ans++;
            }
            i--;
        }
    }
    if(ans >= m){
        return true;
    }
    return false;
}   

int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
    vvi a(arr.size(), vi(2, 0));
    for(int i=0;i<arr.size();i++){
        a[i][0] = arr[i];
        a[i][1] = i;
    }
    int n = arr.size();
    sort(all(a), func);
    int s = 0;
    int e = n-1;
    int ans = INT_MAX;
    while(s<=e){
        int mid = (s+e)/2;
        int x = a[mid][0];
        if(check(x, arr, k, m)){
            ans = x;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}