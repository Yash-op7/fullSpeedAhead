#include <bits/stdc++.h>
using namespace std;

int find_parent(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;
    return parent[node] = find_parent(parent[node], parent);
}
int motherVertex(int A, vector<vector<int>> &B)
{
    vector<int> parent(A + 1);
    for (int i = 1; i <= A; i++)
        parent[i] = i;
    for (int i = 0; i < B.size(); i++)
    {
        int u = B[i][0];
        int v = B[i][1];
        u = find_parent(u, parent);
        v = find_parent(v, parent);
        parent[v] = u;
        for(int i=1;i<=A;i++){
            cout<<parent[i]<<" ";
        }cout<<endl;
    }

    for (int i = 1; i <= A; i++)
    {   cout<<i<<" -> ";
        cout<<parent[i]<<" ";
        find_parent(i, parent);
        cout<<parent[i]<<"\n";
    }
    cout<<endl;
    set<int> st;
    for (int i = 1; i < A + 1; i++)
    {
        st.insert(parent[i]);
    }
    //    for(auto x:st){
    //        cout<<x<<endl;
    //    }cout<<st.size()<<endl;
    int num = st.size();
    for(auto x:st){
        cout << "ans could be -> " << x<< '\n';
    }
    return num == 1;
}

int main()
{
    int a;
    cin >> a;
    int edges;
    cin >> edges;
    vector<vector<int>> b(edges);
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        b[i] = {x, y};
    }
    cout << motherVertex(a, b);
}