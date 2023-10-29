#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int solve(vector<int> &a)
{
    int n = a.size(), l = 0, r = n - 1;
    set<pair<int, int>> minHeap;
    set<pair<int, int>, greater<pair<int, int>>> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.insert({a[i], i});
        minHeap.insert({a[i], i});
    }

    int ans = 0;

    while ((*minHeap.begin()).first * 2 < (*maxHeap.begin()).first)
    {
        int loc_min = (*minHeap.begin()).second;            // location of minimum element
        int loc_max = (*maxHeap.begin()).second;            // location of maximum element
        int dist1 = min(abs(l - loc_min), abs(r - loc_min));        // minimimum number of removals required to remove the current minimum
        int dist2 = min(abs(l - loc_max), abs(r - loc_max));        // minimimum number of removals required to remove the current maximum

        if (dist1 < dist2)
        {
            // when we need to remove the smaller element
            if (abs(l - loc_min) < abs(r - loc_min))
            {
                while (l <= loc_min)
                {
                    minHeap.erase({a[l], l});
                    maxHeap.erase({a[l], l} );
                    l++;
                    ans++;
                }
            }
            else
            {
                while (r >= loc_min)
                {
                    minHeap.erase({a[r], r});
                    maxHeap.erase({a[r], r});
                    r--;
                    ans++;
                }
            }
        }
        else
        {
            // else its more optimal to remove the larger element
            if (abs(l - loc_max) < abs(r - loc_max))
            {
                while (l <= loc_max)
                {
                    maxHeap.erase({a[l], l});
                    minHeap.erase({a[l], l});
                    l++;
                    ans++;
                }
            }
            else
            {
                while (r >= loc_max)
                {
                    maxHeap.erase({a[r], r});
                    minHeap.erase({a[r], r});
                    r--;
                    ans++;
                }
            }
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(a)<<'\n';
}