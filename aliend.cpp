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

string merge(string a, string b){
    string ans = "";
    int n = a.length();
    int m = b.length();
    int i=0;
    int j = 0;
    while(i<n && j <m){
        if(a[i] < b[j]){
            ans += a[i];
            i++;
        }else{
            ans += b[j];
            j++;
        }
    }
    while(i<n){
        ans += a[i];
        i++;
    }
    while(j<m){
        ans += b[j];
        j++;
    }
    return ans;
}

string alienOrder(vector<string> &a, int n)
{
    // Write your code here
    vi out(26, -1);
    vi ind(26, -1);
    unordered_map<char, vector<char>> adj;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].length();j++){
            ind[a[i][j] - 'a'] = 0;
            out[a[i][j] - 'a'] = 0;
        }
    }
    for (int i = 1; i < a.size(); i++)
    {
        string one = a[i - 1];
        string two = a[i];
        for (int j = 0; j < min(one.length(), two.length()); j++)
        {
            char c = one[j];
            char d = two[j];
            if (out[c - 'a'] == -1)
            {
                out[c - 'a'] = 0;
            }
            if (ind[c - 'a'] == -1)
            {
                ind[c - 'a'] = 0;
            }
            if (c != d)
            {
                if (out[d - 'a'] == -1)
                {
                    out[d- 'a'] = 0;
                }
                if (ind[d - 'a'] == -1)
                {
                    ind[d - 'a'] = 0;
                }
                ind[c - 'a']++;
                out[d - 'a']++;
                adj[d].push_back(c);
                break;
            }
        }
    }
    string indep = "";
    for (int i = 0; i < 26; i++)
    {
        sort(all(adj[(char)(i + 'a')]));
        if (ind[i] == 0 && out[i] == 0)
        {
            indep += (char)(i + 'a');
        }
    }
    sort(all(indep));

    queue<char> q;
    for (int i = 0; i < 26; i++)
    {
        if (ind[i] == 0 && out[i] != 0)
        {
            q.push((char)(i + 'a'));
        }
    }
    string ans = "";
    while (!q.empty())
    {
        char c = q.front();
        q.pop();
        ans = c  + ans;
        for (char next : adj[c])
        {
            ind[next - 'a']--;
            if (ind[next - 'a'] == 0)
            {
                q.push(next);
            }
        }
    }
    cout<<ans<<" & "<<indep<<endl;
    ans = merge(ans, indep);
    return ans;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << alienOrder(a, n) << endl;
    }
}