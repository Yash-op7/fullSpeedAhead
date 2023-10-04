#include <bits/stdc++.h> 
using namespace std;
/************************************************************
    Following is the Binary Tree node structure:

    
*************************************************************/

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

void f(TreeNode* root, vector<int> v){
    if(root == NULL){
        return;
    }
    f(root->left, v);
    v.push_back(root->data);
    f(root->right, v);
}

void recoverTree(TreeNode* root) {
    // Write your code here.
    vector<int> inorder;
    f(root, inorder);
    for(int x:inorder){
        cout<<x<<' ';
    }
}

int main(){
    
}













