#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int maxAdjDifference(vector<int> &a, int k)
{
    // Write your code here.
    int n = a.size();
    multiset<vi, greater<vi>> mset;
    for (int i = 1; i < n; i++)
    {
        mset.insert({a[i] - a[i - 1], i});
    }
    for(auto x:mset){
        cout<<x[0]<<" "<<x[1]<<endl;
    }
    bool flag = false;
    int ans = (*mset.begin())[0];
    int s = 0;
    int e = n - 1;
    int c1, c2;
    while (!mset.empty() && k > 0)
    {
        cout<<"start is "<<s<<" end is "<<e<<endl;
        vi top = *mset.begin();
        if (flag)
        {
            if (c1 > top[0])
            {
                return c1;
            }
        }
        c1 = top[0];
        c2 = top[1];
        mset.erase(mset.begin());

        int first = c2 - s;
        int last = e - c2 + 1;
        if (first < last)
        {
            if (k >= first)
            {
                s = c2;
                k -= first;
                if (mset.empty())
                {
                    return 0;
                }
                else
                {
                    ans = (*mset.begin())[0];
                }
                flag = false;
            }
            else
            {
                flag = true;
            }
        }
        else
        {
            if (k >= last)
            {
                e = c2 - 1;
                k -= last;
                if (mset.empty())
                {
                    return 0;
                }
                else
                {
                    ans = (*mset.begin())[0];
                }
                flag = false;
            }
            else
            {
                flag = true;
            }
        }
    }
    while (!mset.empty())
    {
        vi front = *mset.begin();
        int i = front[1];
        if (i > e || i <= s || (i - front[0]) < s)
        {
            mset.erase(mset.begin());
        }
        else
        {
            cout<<s<<" "<<e<<" "<<front[1]<<endl;;
            
            return front[0];
        }
    }
    cout<<"y";
    return 0;
}
int main(){
    int n, k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<maxAdjDifference(a, k);
}