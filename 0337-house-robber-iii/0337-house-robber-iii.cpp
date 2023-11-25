/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root, bool canRob, map<pair<TreeNode*, bool>, int> &t){
        if(root == nullptr){
            return 0;
        }
        if(t.find({root, canRob}) != t.end()) {
            return t[{root, canRob}];
        }
        if(canRob){
            int a = f(root->left, false, t) + f(root->right, false, t) + root->val;
            int b = f(root->left, true, t) + f(root->right, true, t);
            return t[{root, canRob}]= max(a, b);
        }else{
            return t[{root, canRob}]= f(root->left, true, t) + f(root->right, true, t);
        }
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*, bool>, int> t;
        return f(root, true, t);
    }
};