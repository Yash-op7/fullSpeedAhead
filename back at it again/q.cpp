#include<bits/stdc++.h>
using namespace std;

string mergeback(string str, string x){
    string ans = "";
    for (int i = max(0, (int)(str.length() - x.length())); i < str.length(); i++)
    {
        if (str.substr(i) == x.substr(0, min(x.length(), str.length() - i)))
        {
            cout << "merging " << str << " and " << x << " into ";

            return str + x.substr(str.length());
        }
    }
    cout<<"merging "<<str<<" and "<<x<<" into ";
    return str+x;
}


int f(string str, int mask, vector<string>&a){
    int n = a.size();
    if(mask == (1<<n) - 1){
        return str.length();
    }
    if(mask == 0){
        int ans = 1e9;
        for(int i=0;i<n;i++){
            ans = min(ans, f(a[i], mask | (1<<i), a));
        }
        return ans;
    }else{
        int ans = 1e9;
        for(int i=0;i<n;i++){

            if(!((mask>>i)&1)){
                string temp1 = mergeback(str, a[i]);
                cout<<temp1<<'\n';
                ans = min(ans, f(temp1, mask|(1<<i), a));
                temp1 = mergeback(a[i], str);
                cout<<temp1<<'\n';
                ans = min(ans, f(temp1, mask|(1<<i), a));
            }
        }
        return ans;
    }
}

int solve(vector<string> &A) {
    return f("" ,0, A);
}

int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        a[i] = x;
    }
    cout<<solve(a);
}