#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
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

int f(int idx, int last, vvi &a, vvi &t){
    if(idx == a.size()){
        return 0;
    }
    if(last != -1){
        if(t[idx][last] != -1){
            return t[idx][last];
        }
    }
    int currAge = a[idx][0];
    int currSkill = a[idx][1];
    if(last != -1){
        int prevAge = a[last][0];
        int prevSkill = a[last][1];

        int take = INT_MIN;
        if(currAge == prevAge){
            take = currSkill + f(idx+1, idx, a, t);
        }else{
            if(currSkill >= prevSkill){
                take = currSkill + f(idx +1, idx, a, t);
            }
        }
        int dont = f(idx+1, last, a, t);
        return t[idx][last] = max(take, dont);
    }else{
        int take = currSkill + f(idx+1, idx, a, t);
        int dont = f(idx+1, last, a, t);
        return max(take, dont);
    }
}

int perfectTeam(vector<int> &age, vector<int> &skill, int n)
{
    // Write your code here.
    vvi a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = {age[i], skill[i]};
    }
    sort(all(a));
    int maxAge = a.back()[0];

    vvi t(n, vi(n, -1));
    return f(0, -1, a, t);
}