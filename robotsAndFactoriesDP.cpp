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

class Solution
{
public:
    ll f(int idxRobot, int idxFactory, vi &robots, vvi &factories, vvl &t)
    {
        if (idxRobot == robots.size())
        {
            return 0;
        }
        if (idxFactory == factories.size())
        {
            return INT_MAX;
        }
        if (t[idxRobot][idxFactory] != -1)
        {
            return t[idxRobot][idxFactory];
        }
        if (factories[idxFactory][1] > 0)
        {
            factories[idxFactory][1]--;
            ll repair = f(idxRobot + 1, idxFactory, robots, factories, t) + abs(robots[idxRobot] - factories[idxFactory][0]);
            factories[idxFactory][1]++;
            ll dontRepair = f(idxRobot, idxFactory + 1, robots, factories, t);

            return t[idxRobot][idxFactory] = min(repair, dontRepair);
        }
        else
        {
            return t[idxRobot][idxFactory] = f(idxRobot, idxFactory + 1, robots, factories, t);
        }
    }

    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(all(robot));
        sort(all(factory));
        vvl t(robot.size(), vl(factory.size(), -1));
        return f(0, 0, robot, factory, t);
    }
};