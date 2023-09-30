
#include<bits/stdc++.h>
using namespace std;

double f2(int x){
    double ans = 1;
    while(x>0){
        ans/=4;
        x--;
    }
    return ans;
}
int main(){
    cout<<f2(2)<<endl;
}