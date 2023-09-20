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

void print(vi &a)
{
    for (const auto &x : a)
    {
        cout << x << " ";
    }
    cout << '\n';
}

bool func(vi &a, vi &b){
    return a[0] > b[0];
}

bool func2(vi &a, vi &b){
    return a[1] < b[1];
}

vi solve(vi &a){
    int n = a.size();
    vvi arr(n, vi(2));
    for(int i=0;i<n;i++){
        arr[i][0] = a[i];
        arr[i][1] = i;
    }
    sort(all(arr), func);
    for(int i=0;i<n;i++){
        arr[i][0] = i+1;
    }
    sort(all(arr), func2);
    for(int i=0;i<n;i++){
        a[i] = arr[i][0];
    }
    return a;
}

string f(string &str){
    int n = str.length();
    int needToChange= 0;
    int dont= 0;
    int s = 0;
    int e = n-1;
    while(s<e){
        if(str[s] != str[e]){
            needToChange++;
        }else{
            dont+=2;
        }
        s++;
        e--;
    }
    if(s == e){
        dont++;
    }
    string ans = "";
    for(int i=0;i<=n;i++){
        if(i < needToChange){
            ans += "0";
        }else{
            int extra = i - needToChange;
            if( extra == 0){
                ans +="1";
            }else{
                if(dont%2 == 0){
                    if(extra%2 == 0){
                        if(extra <= dont){
                            ans += "1";
                        }else{
                            ans+= "0";
                        }
                    }else{
                        ans+="0";
                    }
                }else{
                    if(extra%2 == 0){
                        if(extra < dont){
                            ans += "1";
                        }else{
                            ans+="0";
                        }
                    }else{
                        if(extra <= dont){
                            ans+='1';
                        }else{
                            ans += '0';
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string str;
        getline(cin ,str);
        getline(cin ,str);
        cout<<f(str)<<endl;
    }
}