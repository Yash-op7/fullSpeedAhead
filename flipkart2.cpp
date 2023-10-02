#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin>>tt;
    string s;
    getline(cin, s);
    while(tt--){
        string str;
        getline(cin, str);
        int l = 0;
        int r = 0;
        vector<int> fo(26, -1);
        vector<int> lo(26, -1);
        for (int i = 0; i < str.length(); i++)
        {
            if (fo[str[i] - 'a'] == -1)
            {
                fo[str[i] - 'a'] = i;
            }
        }
        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (lo[str[i] - 'a'] == -1)
            {
                lo[str[i] - 'a'] = i;
            }
        }
        vector<int> ans;
        int i = 0;
        int len = str.length();
        while (i < len)
        {
            l = i;
            r = lo[str[i] - 'a'];
            while (l < len && l < r)
            {
                if (lo[str[l] - 'a'] <= r)
                {
                    l++;
                }
                else
                {
                    r = lo[str[l] - 'a'];
                    l++;
                }
            }
            ans.push_back(r - i + 1);
            i = l + 1;
        }
        for (int x : ans)
        {
            cout << x << " ";
        }
        cout << '\n';
    }
}