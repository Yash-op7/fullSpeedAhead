#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pq priority_queue
#define ll long long
#define MOD 1e9 + 7
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;
class Solution
{
public:

    ll f(int idx, int y, string &s1, string &s2, string &evil){
        if(idx == s1.length()){
            return 1;
        }
        char c1 = s1[idx];
        char c2 = s2[idx];
        if (y == evil.length() - 1)
        {
            if(evil[y] <c1 && evil[y] > c2){
                return f(idx+1, )
            }
        }
    }

    int findGoodStrings(int n, string s1, string s2, string evil)
    {
        return f(0, 0, s1, s2, evil)%MOD;
    }
};

int main()
{
    Solution temp;
    vi r = {9, 11, 99, 101};
    vvi fact = {
        {10, 1}, {7, 1}, {14, 1}, {100, 1}, {96, 1}, {103, 1}};
    cout << temp.minimumTotalDistance(r, fact);
}