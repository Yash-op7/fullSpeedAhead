#include <bits/stdc++.h>
using namespace std;

string alienOrder(vector<string> &A, int n)

{

    vector<int> graph[26];

    vector<int> deg(26, 0);

    vector<bool> vis(26, 0);

    for (auto it : A)

    {

        for (auto jt : it)

        {

            vis[jt - 'a'] = 1;
        }
    }

    for (int i = 0; i < n - 1; i++)

    {

        string a = A[i], b = A[i + 1];

        int p = a.size(), q = b.size();

        for (int j = 0; j < min(p, q); j++)

        {

            if (a[j] != b[j])

            {

                graph[a[j] - 'a'].push_back(b[j] - 'a');

                deg[b[j] - 'a']++;

                break;
            }
        }
    }

    vector<int> res;

    priority_queue<int, vector<int>, greater<int>> pq;

    int cnt = 0;

    for (int i = 0; i < 26; i++)

    {

        if (vis[i] && deg[i] == 0)

        {

            pq.push(i);
        }

        if (vis[i])

        {

            cnt++;
        }
    }

    while (pq.size() != 0)

    {

        int node = pq.top();

        pq.pop();

        res.push_back(node);

        for (auto child : graph[node])

        {

            deg[child]--;

            if (deg[child] < 0)

            {

                return "";
            }

            if (deg[child] == 0)

            {

                pq.push(child);
            }
        }
    }

    if (res.size() != cnt)

    {

        return "";
    }

    string ans = "";

    for (auto it : res)

    {

        ans += it + 'a';
    }

    return ans;
}