#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
const int nmax = 20005;;

int parent[nmax];
int sz[nmax];

void makeSet(int x)
{
    parent[x] = x;
    sz[x] = 1;
}

int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = find(parent[x]);
    }
}

void unionSet(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a == b)
    {
        return;
    }
    else
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        // Code here
        int offset = 10000;
        for (const auto &x : stones)
        {
            makeSet(x[0]);
            makeSet(x[1] + offset + 1);
            unionSet(x[0], x[1] + offset + 1);
        }
        unordered_map<int, bool> dict;
        int ans = 0;
        for (const auto &x : stones)
        {
            int a = find(x[0]);
            if (dict[a])
            {
                continue;
            }
            dict[a] = true;
            ans++;
        }
        return n - ans;
    }
};
