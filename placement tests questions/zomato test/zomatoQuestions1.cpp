#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

string solve(string A) {
    int n = A.length();
    string ans = "";
    int l,r;
    if(n %2 != 0){
        l = n/2 - 1;
        r = n/2+1;
        ans+=A[n/2];
    }else{
        l = n/2-1;
        r = n/2;
    }
    bool flag=  false;
    bool carry =false;
    while(l>=0 && r<n)
    {
        if(A[r] == '9'){
            carry = true;
            l--;
            r++;
            ans = "" + '0' + ans + '0';
        }else if(A[l] < A[r]){
            string temp= A.substr(0, l);
            string x =temp;
            reverse(all(temp));
            ans = x + A[r] + ans + A[r] + temp;
            return ans;
        }else if(A[l] > A[r]){
            string temp= A.substr(0, l+1);
            string x = temp;
            reverse(all(temp));
            ans  = x + ans + temp;
            return ans;
        }else{
            string temp= A.substr(0, l);
            string x = temp;
            reverse(all(temp));
            ans = x+ (char)((int)A[l] + 1) + ans +(char)((int)A[l] + 1)+ temp;
            return ans;
        }
        
    }
    return ans;
}
