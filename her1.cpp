#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next[2];
    Node()
    {
        for (int i = 0; i < 2; i++)
        {
            next[i] = NULL;
        }
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(int a)
    {
        Node *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int temp = 0;
            if ((a & (1 << i)))
            {
                temp = 1;
            }
            if (curr->next[temp] == NULL)
            {
                curr->next[temp] = new Node();
            }
            curr = curr->next[temp];
        }
    }
    int getMaxXor(int a)
    {
        int ans = 0;
        Node *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            if (curr == NULL)
            {
                return -1;
            }
            int temp = 0;
            if ((a & (1 << i)))
            {
                temp = 1;
            }
            if (curr->next[temp xor 1] == NULL)
            {
                curr = curr->next[temp];
                ans = ans << 1;
            }
            else
            {
                ans += 1;
                ans = ans << 1;
                curr = curr->next[temp xor 1];
            }
        }
        ans /= 2;
        return ans;
    }
};

bool func(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    //	Write your coode here.
    int q = queries.size();
    vector<int> ans(q, 0);
    for (int i = 0; i < q; i++)
    {
        queries[i].push_back(i);
    }
    sort(arr.begin(), arr.end());
    sort(queries.begin(), queries.end(), func);
    Trie *trie = new Trie();
    int j = 0;
    for (int i = 0; i < q; i++)
    {
        if (queries[i][1] >= arr[j])
        {
            while (j < arr.size() && queries[i][1] >= arr[j])
            {
                trie->insert(arr[j]);
                j++;
            }
        }
        ans[queries[i][2]] = trie->getMaxXor(queries[i][0]);
    }
    return ans;
}