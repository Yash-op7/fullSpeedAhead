class Solution {
public:
    bool isPalindrome(string &s){
        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int f(int idx, string &s, int k, vector<int>&t)
    {
        if(idx + k > s.length()){
            return 0;
        }
        if(t[idx] != -1){
            return t[idx];
        }
        string str = s.substr(idx, k);
        string str2 = s.substr(idx, k+1);
        if(isPalindrome(str) && str.length() == k){
            t[idx] = max(1 + f(idx+k ,s, k, t) ,f(idx+1, s, k, t));
        }
        if(isPalindrome(str2) && str2.length() == k+1){
            return t[idx]= max(max(1 +f(idx+k+1, s, k, t), f(idx+1, s, k, t)), 
            t[idx]);
        }
        return t[idx]= max(t[idx], f(idx+1, s, k, t));
    }
    int maxPalindromes(string s, int k) {
        vector<int> t(s.length()+1, -1);
        int ans = f(0, s, k ,t);
        if(ans < 0){
            return 0;
        }
        return ans;
    }
};