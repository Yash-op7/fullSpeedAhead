#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

double f2(int x)
{
    double ans = 1;
    while (x > 0)
    {
        ans /= 4;
        x--;
    }
    return ans;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string str;
    getline(cin, str);
    int sx, sy;
    vector<vector<char>> maze(n, vector<char>(m, '0'));
    // map<vi, bool> exits;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = str[j];
            if (str[j] == 'A')
            {
                sx = i;
                sy = j;
            }
        }
    }
    map<pair<int, int>, pair<int, int>> tunnels;
    for (int i = 0; i < k; i++)
    {
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        tunnels[{x, y}] = {z, w};
        tunnels[{z, w}] = {x, y};
    }
    queue<vector<int>> q;
    q.push({sx, sy});
    q.push({});
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[sx][sy] = true;
    int curr = 0;
    vi dx = {0, 0, -1, 1};
    vi dy = {1, -1, 0, 0};
    while (!q.empty())
    {
        vi present = q.front();
        q.pop();
        if (present.empty())
        {
            if(!q.empty()){
                curr++;
                q.push({});
            }
        }
        else
        {
            int x = present[0];
            int y = present[1];
            if (maze[x][y] == '%')
            {
                cout << f2(curr) << '\n';
                return 0;
            }
            for(int i=0;i<4;i++){
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(tx < n && tx >=0 && ty < m && ty >=0 && !vis[tx][ty] &&  (maze[tx][ty] != '#' && maze[tx][ty] != '*')){
                    if(tunnels.find({tx, ty}) != tunnels.end()){
                        pair<int,int> dest = tunnels[{tx, ty}];
                        x = dest.first;
                        y = dest.second;
                        for(int j=0;j<4;j++){
                            int ttx = x + dx[j];
                            int tty = y + dy[j];
                            if(ttx >=0 && ttx <n && ttx >= 0 && tty <m && !vis[ttx][tty] && maze[ttx][tty] != '#' && maze[ttx][tty] != '*'){
                                vis[ttx][tty] = true;
                                q.push({ttx, tty});
                            }
                        }
                        vis[tx][ty] = true;
                        vis[x][y] = true;
                    }else{
                        vis[tx][ty] = true;
                        q.push({tx, ty});
                    }
                }
            }
        }
    }
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
