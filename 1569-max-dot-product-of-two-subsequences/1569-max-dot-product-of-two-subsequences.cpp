class Solution {
public:
    int f(int x,int y, bool hasToTake, vector<int> &a, vector<int> &b, vector<vector<vector<int>>> &t){
        if(x == a.size() || y==b.size()){
            if(hasToTake){
                return -1e9;
            }
            return 0;
        }
        if(t[x][y][hasToTake] != -1){
            return t[x][y][hasToTake];
        }
        if(hasToTake){
            int p,q,r;
            p = a[x] * b[y] + f(x+1, y+1, false, a, b, t);
            q = f(x+1, y, hasToTake, a, b, t);
            r = f(x, y+1, hasToTake, a, b, t);
            return t[x][y][hasToTake] = max({p, q, r});
        }else{
            int p, q, r;
            if(a[x]*b[y] > 0){
                p = a[x]*b[y] + f(x+1, y+1, false, a, b, t);
            }else{
                p = -1;
            }
            q = f(x+1, y, hasToTake, a, b, t);
            r = f(x, y+1, hasToTake, a, b, t);
            return t[x][y][hasToTake] = max({p, q, r});
        }
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<vector<int>>>t(nums1.size(), vector<vector<int>>(nums2.size(), vector<int>(2, -1)));
        return f(0, 0, true, nums1, nums2, t);
    }
};