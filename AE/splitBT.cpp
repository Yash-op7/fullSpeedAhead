using namespace std;

// This is an input class. Do not edit.
class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

int getSum(BinaryTree *root)
{
    if(root == nullptr){
        return 0;
    }
    int leftSum = getSum(root->left);
    int rightSum = getSum(root->right);
    return root->value+leftSum+rightSum;
}

int f(BinaryTree* root, int s){
    if(root=nullptr){
        return 0;
    }
    int leftSum = getSum(root->left);
    int rightSum = getSum(root->right);
    if(root->value + leftSum + rightSum == s){
        return true;
    }
    return f(root->left, s) || f(root->right, s);
}

int splitBinaryTree(BinaryTree *tree)
{
    // Write your code here.
    int sum = getSum(tree);
    if(sum%2==0){
        if(f(tree, sum/2) ){
            return sum/2;
        }
    }
    return -1;
}
