#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define pq priority_queue
#define ll long long
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll INF = 1e12;
const int MOD = 1e9 + 7;

class Solution {
public:
    bool check(string &a, string &b){
        int cnt = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                if(cnt>0){
                    return false;
                }
                cnt++;
            }
        }
        return true;
    }
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        // 11:08:47
        int n = wordList.size();
        if(endWord == beginWord){
            vector<vector<string>> ans;
            ans.push_back({endWord});
            return ans;
        }
        unordered_map<string, vector<string>> adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string word1 = wordList[i];
                string word2 = wordList[j];
                if(check(word1, word2)){
                    adj[word1].push_back(word2);
                    adj[word2].push_back(word1);
                }
            }
        }
        if(adj[beginWord].empty()){
            for(int i=0;i<n;i++){
                if(check(beginWord, wordList[i])){
                    adj[beginWord].push_back(wordList[i]);
                    adj[wordList[i]].push_back(beginWord);
                }
            }
        }
        if(adj[beginWord].empty()){
            return {};
        }  
        unordered_map<string, string> ancestor;
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, bool> vis;
        vis[beginWord] = true;
        ancestor[beginWord] = "$";
        
        vector<vector<string>>ans;
        bool flag = true;
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(string next:adj[curr]){
                if(next == endWord){
                    q.push(curr);
                    flag = false;
                    break;
                }else{
                    if(!vis[next]){
                        q.push(next);
                        ancestor[next] = curr;
                    }
                }
            }
            if(!flag){
                break;
            }
        }
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(find(all(adj[curr]), endWord) != adj[curr].end()){
                vector<string> p = {endWord, curr};
                while(ancestor[curr] != "$"){
                    p.push_back(ancestor[curr]);
                    curr = ancestor[curr];
                }
                reverse(all(p));
                ans.push_back(p);
            }
        }
        return ans;
    }
};