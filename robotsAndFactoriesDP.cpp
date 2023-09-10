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
    ll f(int idxRobot, int idxFactory, vi &robots, vvi &factories)
    {
        if (idxRobot == robots.size())
        {
            return 0;
        }
        if (idxFactory == factories.size())
        {
            return INT_MAX;
        }
        if (factories[idxFactory][1] > 0)
        {
            factories[idxFactory][1]--;
            ll x = f(idxRobot + 1, idxFactory, robots, factories);
            if(x >= INT_MAX){
                return f(idxRobot, idxFactory + 1, robots, factories);
            }
            ll repair = x + abs(robots[idxRobot] - factories[idxFactory][0]);
            factories[idxFactory][1]++;
            ll dontRepair = f(idxRobot, idxFactory + 1, robots, factories);
            if(dontRepair >= INT_MAX){
                return repair;
            }
            return min(repair, dontRepair);
        }
        else
        {
            return f(idxRobot, idxFactory + 1, robots, factories);
        }
    }

    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(all(robots));
        sort(all(factory));
        return f(0, 0, robot, factory);
    }
};