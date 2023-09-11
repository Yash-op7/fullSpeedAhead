
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

int knight(int A, int B, int C, int D, int E, int F)
{
    C--;
    D--;
    E--;
    F--;
    if(!(C<A && C>=0 && D<B && D>=0 && E>=0 && E< A && F>=0 && F<B)){
        return -1;
    }
    vector<vb> vis(A, vb(B, false));
    queue<vi> q;
    q.push({C, D});
    q.push({});
    int dist = 0;
    vis[C][D] = true;

    vi dx = {-2, -2, -1, 1, 2, 2, -1, 1};
    vi dy = {-1, 1, 2, 2, 1, -1, -2, -2};

    while(!q.empty()){
        vi front = q.front();
        q.pop();
        if(front.empty()){
            dist++;
            if(q.empty()){
                break;
            }else{
                q.push({});
            }
        }else{
            int x = front[0];
            int y = front[1];
            if(x == E && y == F){
                return dist;
            }
            for(int i=0;i<8;i++){
                int tx = x+dx[i];
                int ty = y+dy[i];
                if(tx < A && tx >= 0  && ty < B && ty>=0 && !vis[tx][ty]){
                    vis[tx][ty] = true;
                    q.push({tx, ty});
                }
            }
        }
    }
    return -1;
}
