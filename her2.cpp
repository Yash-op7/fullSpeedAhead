#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];
};

class trie
{
    Node *root;

public:
    trie()
    {
        root = new Node();
    }

    void insert(int n)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (node->links[bit] == nullptr)
            {
                node->links[bit] = new Node();
            }
            node = node->links[bit];
        }
    }

    int maxXOR(int a)
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
            if (curr->links[temp xor 1] == NULL)
            {
                curr = curr->links[temp];
                ans = ans << 1;
            }
            else
            {
                ans += 1;
                ans = ans << 1;
                curr = curr->links[temp xor 1];
            }
        }
        ans /= 2;
        return ans;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    //	Write your coode here.
    int n = arr.size();
    int m = queries.size();
    vector<int> ans(m, 0);
    vector<vector<int>> temp;
    trie tr;
    for (int i = 0; i < m; i++)
    {
        temp.push_back({queries[i][1], queries[i][0], i});
    }
    sort(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while (arr[j] <= temp[i][0])
        {
            tr.insert(arr[j]);
            j++;
        }
        int x = tr.maxXOR(temp[i][1]);
        ans[temp[i][2]] = x;
    }
    return ans;
}