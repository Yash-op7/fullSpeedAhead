
bool check(int idx, string &s, unordered_map<string, bool>&dict){
    if(idx == s.length()){
        return true;
    }
    string str = "";
    for(int i=idx;i<s.length();i++){f
        str += s[i];
        if(dict[str]){
            if(check(i+1, s, dict)){
                return true;
            }
        }
    }
    return false;
}

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // 11:37
        unordered_map<string, bool>dict;
        for(const auto x:words){
            dict[x] =true;
        }
        vector<string> ans;
        for(auto x:words){
            dict[x] = false;
            if(check(0, x, dict)){
                ans.push_back(x);
            }
            dict[x] = true;

        }
        return ans;
    }
};