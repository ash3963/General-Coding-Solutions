#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* rightMostHelper(TreeNode* root) {
    if(!root->right)
        return root;
    return rightMostHelper(root->right);
}

void flatten(TreeNode* root) {
    if(!root)
        return;
    TreeNode* nextRight;
    TreeNode* rightMost;
    while(root) {
        if(root->left) {
            nextRight = root->right;
            rightMost = rightMostHelper(root->left);
            root->right = root->left;
            root->left = NULL;
            rightMost->right = nextRight;
        }
        root = root->right;
    }
}