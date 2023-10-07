
/*
    Time complexity: O((N + M)logN)
    Space complexity: O(N + M)

    Where ‘N’ is the number of cities and ‘M’ is the number of trains connecting the cities.
*/
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

#define endl "\n";
const int NUM = 1006;
int u[NUM];
int v[NUM];
int val[NUM];
int n, m, k;
vector<int> graph[NUM];
stack<int> sccStack;
bool visit[NUM];
int componentsSz[NUM];
int componentsCount = 0;

// Utility function to store the nodes in stack in 'kosaraju algorithm'
void dfs(int node) {
    visit[node] = 1;

    for(int i: graph[node]) 
    {
        if(visit[i] == 0) 
        {   
            dfs(i);
        }
    }

    sccStack.push(node);
}

// Utility function that counts the number of nodes in a component 
void dfs2(int node) 
{
    componentsSz[componentsCount]++;
    visit[node] = 1;
    for(int i: graph[node]) 
    {      
        if(visit[i] == 1)
            continue;

        dfs2(i);
    }
}

bool check(int limit) 
{
    // Take a variable that count the number of component
    componentsCount = 0;

    memset(visit, 0, sizeof(visit));

    // Clear stack
    while( ! sccStack.empty()) 
    {
        sccStack.pop();
    }

    // Clear graph
    for(int i = 1; i <= n; i++) 
    {
        graph[i].clear();
    }

    // Run a loop from 1 to 'm' and add the edge to the graph which satisfies the condition
    for(int i = 1; i <= m; i++) 
    {
        int a = u[i], b = v[i];

        // If nodes values is greater than limit 
        if(val[a] >= limit && val[b] >= limit) 
        {
            graph[a].push_back(b);
        }
    }

    // Run a loop from 1 to 'n' and store nodes in stack (kosaraju algorithm)
    for(int i = 1; i <= n; i++) {
        if(visit[i] == 0) {
            dfs(i);
        }
    }
    // Clear graph
    for(int i = 1; i <= n; i++) 
        graph[i].clear();

    memset(visit, 0, sizeof(visit));

  // Create graph by reversing the edges
   for(int i = 1; i <= m; i++) 
   {
        int a = u[i], b = v[i];

        if(val[a] >= limit && val[b] >= limit)
        {
            graph[b].push_back(a);
        }
    }

    // Run through stack
    while(sccStack.size()) 
    {
        // Get the top node in stack
        int cur = sccStack.top();

        // Remove node from stack
        sccStack.pop();

        // If this node is not already visited then perform dfs to count the number of nodes in this component
        if(visit[cur] == 1)
            continue;

        ++componentsCount;
        
        dfs2(cur);
    }

    int ans = 0;

    // Find the maximum counts of nodes and store in variable 'ans'
    for(int i = 1; i <= componentsCount; i++) 
    {
        ans = max(ans , componentsSz[i]);
        componentsSz[i] = 0;
    }

    componentsCount = 0;
    
    // If 'ans' is greater than given 'k' return 1.
    if(ans >= k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Utility function for Initialition
void init(vector<int> & value,vector<int> & U, vector<int> & V, int K)
{
    n = value.size();
    m = V.size();
    k = K;

    for(int i = 1; i <= m ;i++){

        u[i] = U[i-1];
        v[i] = V[i-1];
    }

    for(int i = 1; i <= n; i++){
        val[i] = value[i-1];
        visit[i] = 0;
    }
}

int MaxValueOfK(vector < int > & arr, vector < int > & U, vector < int > & V, int K)
{
    init(arr, U, V, K);

    // Initialize lower answer with 1 and upper answer with 10 ^ 9
    int l = 1, r = 1000000000;

    // If there is no component, then return -1
    int ans = -1;

    // Applying binary search while l <= r
    while(l <= r) 
    {
        // Find mid
        int mid = (l + r) / 2;

        // Check whether there exists any component of size greater than or equal to 'mid' which satisfies all constraints
        if(check(mid) == 1) 
        {
            // Store mid in 'ans'
            ans = mid;

            l = mid + 1;
        }
        else 
        {
            r = mid - 1;
        }
    }

    // Retunr ans
    return ans;
}