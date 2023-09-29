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

int f(int n){
    int ans = 0;
    int k = 1;
    while(true){
        k*=5;
        ans += (n/k);
        if(n/k == 0){
            break;
        }
    }
    return ans;
}

int help(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x % 5 == 0)
        {
            count++;
            x = x / 5;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    cout<<help(n)<<endl;
}