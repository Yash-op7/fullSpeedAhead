int find_parent(int node, vector<int> &parent){
    if(node == parent[node]) return node;
    return parent[node] = find_parent(parent[node], parent);
}
int Solution::motherVertex(int A, vector<vector<int> > &B) {
   
   vector<int> parent(A+1);
   for(int i=0; i<=A; i++) parent[i] =i;
   for(int i=0; i<B.size(); i++){
       int u= B[i][0];
       int v=B[i][1];
       u = find_parent(u,parent);
       v = find_parent(v,parent);
      
       parent[v] = u;
   }
   
   for(int i=1; i<=A; i++){
        find_parent(i, parent); 
    }
   set<int> st;
   for(int i=1; i<A+1; i++) st.insert(parent[i]);
   
  
 
 int num = st.size();
 return num == 1;
    
}