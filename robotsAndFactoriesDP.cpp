#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pq priority_queue
#define ll long long
#define MOD 1e9 + 7
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
class Solution
{
public:
    ll f(int idxRobot, int idxFactory, vi &robots, vvi &factories, vector<vvl> &t)
    {
        if (idxRobot == robots.size())
        {
            return 0;
        }
        if (idxFactory == factories.size())
        {
            return INF;
        }
        if (t[idxRobot][idxFactory][factories[idxFactory][1]] != -1)
        {
            return t[idxRobot][idxFactory][factories[idxFactory][1]];
        }
        if (factories[idxFactory][1] > 0)
        {
            factories[idxFactory][1]--;
            ll repair = f(idxRobot + 1, idxFactory, robots, factories, t) + abs(robots[idxRobot] - factories[idxFactory][0]);
            factories[idxFactory][1]++;
            ll dontRepair = f(idxRobot, idxFactory + 1, robots, factories, t);
            if (factories[idxFactory][0] >= robots[idxRobot])
            {
                return t[idxRobot][idxFactory][factories[idxFactory][1]] = repair;
            }
            return t[idxRobot][idxFactory][factories[idxFactory][1]] = min(repair, dontRepair);
        }
        else
        {
            return t[idxRobot][idxFactory][factories[idxFactory][1]] = f(idxRobot, idxFactory + 1, robots, factories, t);
        }
    }

    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(all(robot));
        sort(all(factory));
        // vvl t(robot.size(), vl(factory.size(), -1));
        vector<vvl> t(robot.size(), vvl(factory.size(), vl(101, -1)));
        ;
        return f(0, 0, robot, factory, t);
    }
};


int main()
{
    Solution temp;
    vi r = {9, 11, 99, 101};
    vvi fact = {
        {10, 1}, {7, 1}, {14, 1}, {100, 1}, {96, 1}, {103, 1}
        };
    cout << temp.minimumTotalDistance(r, fact);
}