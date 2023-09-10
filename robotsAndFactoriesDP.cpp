
#define vi vector<int>
#define vvi vector<vi>
#define ll long long

class Solution {
public:

    ll f(int idxRobot, int idxFactory, vi&robots, vvi &factories){
        if(idxRobot == robots.size()){
            return 0;
        }
        if(idxFactory == factories.size()){
            return INT_MAX;
        }
        if(factories[idxFactor])
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        return f(0, 0, robot, factory);
    }
};