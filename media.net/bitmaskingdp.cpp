// 7:10
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define vvi vector<vi>
const int MOD = 1e9 + 7;
vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
const int N = primes.size();

bool canTake(int x, int mask){
    int bit = (mask >> x) & 1;
    if(bit ==1){
        return false;
    }
    return true;
}

int f(int idx, int mask, vi &a, vvi &t){
    if(idx == a.size()){
        if(mask == 0){
            return 0;
        }
        return 1;
    }
    if(t[idx][mask] != -1){
        return t[idx][mask];
    }
    int curr = a[idx];
    bool shouldTake = true;
    for(int i=0;i<N;i++){
        if(primes[i] > a[idx]){
            break;
        }
        if(a[idx] % (primes[i] * primes[i]) == 0){
            shouldTake = false;
            break;
        }
        if (curr % primes[i] == 0)
        {
            if (!canTake(i+1, mask))
            {
                shouldTake = false;
                break;
            }
        }
    }
    
    if(!shouldTake) {
        return t[idx][mask] = f(idx + 1, mask, a, t)%MOD;
    }else{
        int mask2 = mask;
        for(int i=0;i<N;i++){
            if (primes[i] > a[idx])
            {
                break;
            }
            if (curr % primes[i] == 0)
            {
                mask2 = (mask2 | (1 << i+1));
            }
        }

        return t[idx][mask] = (f(idx + 1, mask, a, t) + f(idx + 1, mask2, a, t))%MOD;
    }
}

int main(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m = (1<<N+1);
    // cout<<"m is "<<m*10000<<endl;
    vvi t(n, vi(m, -1));
    cout<< f(0, 0, a, t)<<'\n';
}