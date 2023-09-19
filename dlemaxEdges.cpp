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

bool f(int src, int dest, vvi adj[], int parent, int &ans, map<vi, int> &t)
{
    cout<<src<<" "<<dest<<" "<<ans<<endl;
    if (src == dest)
    {
        return true;
    }
    if (t.find({src, dest}) != t.end())
    {
        ans = t[{src, dest}];
        return true;
    }
    if (t.find({dest, src}) != t.end())
    {
        ans = t[{dest, src}];
        return true;
    }
    int unvisNeighbours = 0;
    for (const auto x : adj[src])
    {
        if (x[0] != parent)
        {
            if (f(x[0], dest, adj, src, ans, t))
            {
                ans = max(ans, x[1]);
                cout<<"dping "<<src<<" "<<dest<<" "<<ans<<endl;;
                t[{src, dest}] = ans;

                unvisNeighbours++;
                break;
            }
        }
    }
    if (unvisNeighbours == 0)
    {
        return false;
    }
    return true;
}

vector<int> solve(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int n = A.size() + 1;
    vvi adj[n + 1];
    for (const auto edge : A)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    vi ans(B.size(), 0);
    int q = B.size();
    int ans1 = INT_MIN;
    map<vi, int> t;
    for (int i = 0; i < q; i++)
    {
        bool k = f(B[i][0], B[i][1], adj, -1, ans1, t);
        ans[i] = ans1;
        ans1 = INT_MIN;
    }
    return ans;
}

int main()
{
    // int n;
    // cin >> n;
    // vvi a(n, vi(3, 0));
    // for (int i = 0; i < n; i++)
    // {
    //     int x, y, wt;
    //     cin >> a[i][0] >> a[i][1] >> a[i][2];
    // }
    // int m;
    // cin >> m;
    // vvi b(m, vi(2, 0));
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> b[i][0];
    //     cin >> b[i][1];
    // }
    vvi g1 = {
        {9, 6, 17036},
        {7, 2, 9895},
        {4, 1, 28704},
        {6, 5, 23812},
        {3, 1, 31323},
        {8, 3, 30334},
        {2, 1, 17674},
        {10, 2, 4665},
        {5, 1, 15142}};
    vvi g2 = {
        {5, 3},
        {1, 5}
        // ,
        // {1, 9},
        // {9, 8},
        // {1, 4},
        // {7, 1},
        // {5, 6},
        // {7, 2},
        // {1, 7}
        };
    vi ans = solve(g1, g2);
    for (auto x : ans)
    {
        cout << x << endl;
    }
}