
#define vi vector<int> 
#define ll long long 
const int MOD = 1e9 + 7;
ll ans;
vi adj[100001];
ll sum;

int dfs(int src, int parent, vi&A){
    ll curr = A[src-1];
    for(int neighbour:adj[src]){
        if(neighbour != parent){
            curr +=dfs(neighbour, src, A);
        }
    }
    ans = max(ans, (curr * (sum - curr)));
    return curr;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    sum = 0;ans = 0;
    for(int i=1;i<=n;i++){
        sum+=A[i-1];
        adj[i].clear();
    }
    for(vi x:B)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    ll t = dfs(1, 0, A);
    return ans%MOD;    