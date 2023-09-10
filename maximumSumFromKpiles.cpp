

#define vi vector<int>

int f(int idx, int loc, int k, vector<vi> &piles, vector<vector<vi>> &t){
    if(idx == piles.size() || k == 0){
        return 0;
    }
    if(t[idx][loc][k] != -1){
        return t[idx][loc][k];
    }
    if(loc == piles[idx].size()){
        return t[idx][loc][k]= f(idx+1, 0, k, piles, t);
    }else{
        return t[idx][loc][k]= max(
            f(idx, loc+1, k-1, piles, t) + piles[idx][loc],
            f(idx+1, 0, k, piles, t)
        );
    }
}


class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int maxLen = 0;
        for(vi &pile:piles){
            maxLen = max(maxLen, (int)pile.size());
        }
        vector<vector<vi>> t(piles.size(), vector<vi>(maxLen+1, vi(k+1, -1)));
        return f(0, 0, k, piles, t);
    }
};