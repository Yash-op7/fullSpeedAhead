#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        set<int> s1, s2;
        set<int> set1, set2;

        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (i % 2 == 0)
            {
                set2.insert(x);
            }
            else
            {
                set1.insert(x);
            }
        }
        bool flag = true;
        bool p = true;
        ll ans = 0;
        int cnt = 0;
        while (flag)
        {
            if (set2.empty() && set1.empty())
            {
                break;
            }
            cnt++;
            if(cnt > 10){
                break;
            }
            if (p)
            {
                // s1
                s1 = set1;
                s2 = set2;
            }
            else
            {
                s1 = set2;
                s2 = set1;
            }
            int largest = *s1.rbegin();
            if (largest > 0)
            {
                ans += largest;
                s1.erase(*s1.rbegin());
                p = !p;
                continue;
            }
            else
            {
                int l2 = *s2.rbegin();
                if (l2 < 0)
                {
                    flag = false;
                    break;
                }
                int sm2 = *s2.begin();
                if (sm2 <= 0)
                {
                    s2.erase(*s2.begin());
                    p = !p;
                }
                else if (sm2 > abs(largest))
                {
                    ans += l2;
                    s2.erase(*s2.rbegin());
                    p = !p;
                }
                else
                {
                    ans += largest;
                    s1.erase(largest);
                    p = !p;
                }
            }
        }
        cout << ans << endl;
    }
}