#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    int l =0; int r = n;
    while( l < r){
        int mid = (l+r)/2;

        if(a[mid] < x){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    cout<<"lower_bound of "<<x<<" is "<<a[r] <<" at "<<r<<endl;
     l = 0;
     r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;

        if (a[mid] <= x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << "upper_bound of " << x << " is " << a[r] << " at " << r << endl;
}