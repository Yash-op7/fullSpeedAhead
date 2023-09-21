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

int f(int idx, int currAge, int currSkillCap, vvi &a){
    if(idx == a.size()){
        return 0;
    }
    int age = a[idx][0];
    int skill = a[idx][1];

    int take =INT_MIN;
    if(currAge == age){
        take = f(idx+1, currAge, max(currSkillCap, skill), a) + skill;
    }else{
        // currAge < age
        if(skill >= currSkillCap){
            take = f(idx+1, age, skill, a) + skill;
        }
    }
    int dont = f(idx+1, currAge, currSkillCap, a);
    return max(take, dont);
}

int perfectTeam(vector<int> &age, vector<int> &skill, int n)
{
    // Write your code here.
    vvi a(n);
    for(int i=0;i<n;i++){
        a[i] = {age[i], skill[i]};
    }
    sort(all(a));
    unordered_map<int, vvi> tf;
    return f(0, 0,  INT_MIN, a, tf);
}