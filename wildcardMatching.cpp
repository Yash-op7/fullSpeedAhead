map<pair<int, int>, int> M;
int suffixLen[50001], len1, len2;
bool helper(const string s, const string p, int index1, int index2) {
    // If we are at the end of both pattern and the string, then its obviously a match
    if (index1 == s.size() && p[index2] == 0) return true;
    // If pattern ends, but the string hasn't, then its not a match
    if (index2 == p.size()) return false;
    // If string ends, then the only permissible character is '*' in the pattern array
    if (index1 == s.size() && p[index2] != '*') return false;
    // If remaining non * characters in pattern are more than the total chars in s, there can't be match
    if (len1 - index1 < suffixLen[index2]) return false;
    // memoized result
    if (M.find(make_pair(index1, index2)) != M.end()) return M[make_pair(index1, index2)];
    // s has ended. We know next character in p is '*'. Lets check other following chars in p
    if (s[index1] == 0) return M[make_pair(index1, index2)] = helper(s, p, index1, index2 + 1);
    // characters match when pattern is not '*'
    if (s[index1] == p[index2] || p[index2] == '?') return M[make_pair(index1, index2)] = helper(s, p, index1 + 1, index2 + 1);
    // If pattern is '*', then explore both possibilities
    if (p[index2] == '*') return M[make_pair(index1, index2)] = (helper(s, p, index1 + 1, index2) || helper(s, p, index1, index2 + 1));
    return M[make_pair(index1, index2)] = false;
}

int isMatch(const string s, const string p) {
    M.clear();
    len1 = s.size();
    len2 = p.size();
    int cnt = 0;
    for (int i = len2 - 1; i >= 0; i--){
        if (p[i] != '*') cnt++;
        suffixLen[i] = cnt;
    }
    return helper(s, p, 0, 0);
}