#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helpSymmetric(TreeNode* left, TreeNode* right){
    if(left == NULL || right == NULL)
        return left== right;
    if(left->val!=right->val)
        return false;
    else
        return helpSymmetric(left->left, right->right) && helpSymmetric(left->right, right->left);
}


bool isSymmetric(TreeNode* root) {
    return root==NULL || helpSymmetric(root->left, root->right);        
}