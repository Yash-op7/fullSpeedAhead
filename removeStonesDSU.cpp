
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pq priority_queue
#define ll long long
#define MOD 1e9 + 7
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)

const int nmax = 1e3 + 5;

class DSU
{
public:
    int parent[nmax];
    int sz[nmax];
    unordered_map<pair<int, int>, int> mapper;
    unordered_map<int, pair<int, int>> rmapper;
    DSU(){
        
    }
    void makeSet(int x, int y, int i)
    {
        mapper[make_pair(x, y)] = i;
        rmapper[i] = make_pair(x, y);
        parent[i] = i;
        sz[i] = 1;
    }

    int find(int x, int y)
    {
        int x = mapper[make_pair(x, y)];
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(rmapper[parent[x]].first, rmapper[parent[x]].second);
    }

    void unionSet(int x, int y, int p, int q)
    {
        int a = mapper[make_pair(x, y)];
        int b = mapper[make_pair(p, q)];
        if (a == b){
            return;
        }else{
            if(sz[a] < sz[b]){
                swap(a, b);
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int maxRemove(vector<vector<int>> &stones, int n)
{
    // Code here
    unordered_map<int, vi> adjx;
    unordered_map<int, vi> adjy;
    DSU *dsu = new DSU();

    for(int i=0;i<n;i++){
        vi curr = stones[i];
        adjx[curr[0]].push_back(curr[1]);
        adjy[curr[1]].push_back(curr[0]);
        dsu->makeSet(curr[0], curr[1], i+1);
    }
    for(int i=0;i<n;i++){
        vi curr = stones[i];
        int x = curr[0];
        for(auto &y:adjx[x]){
            
        }
    }
}