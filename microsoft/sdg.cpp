// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N, int M, vector<int> &X1, vector<int> &Y1, vector<int> &X2, vector<int> &Y2) {
    vector<vector<int>> A(N, vector<int>(M,1));
    int n1 = X1.size();
    int n2 = X2.size();
    for(int i=0; i<n1; i++) A[X1[i]][Y1[i]] =1e9;
    for(int i=0; i<n2; i++) A[X2[i]][Y2[i]] =1e9;

    int drow[4] = {0,1,0,-1};
    int dcol[4] = {1,0,-1,0};
  
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  vector<vector<int>> dist(N, vector<int> (M,1e9));
  dist[0][0] =0;
  pq.push({0,0,0});
  while(!pq.empty()){
      auto it = pq.top();
      pq.pop();
      int dis = it[0];
      int row = it[1];
      int col = it[2];
      for(int i=0; i<4;i++){
          int r = row + drow[i];
          int c= col + dcol[i];
          if(r>=0 && r<N && c>=0 && c< M && A[r][c] != 1e9){
              
               
                if(dist[r][c] > 1+dis){
                  dist[r][c] = 1+dis;
                  pq.push({dis+1,r,c});
                    
                }
                
                
              
        }
      }
  }
  
  return dist[N-1][M-1];
    



}