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


int getDepth(TreeNode* root) {
    if(!root) return 0;
    return max(getDepth(root->left), getDepth(root->right)) + 1;
}


TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    if(!root) return NULL;
    int rightD = getDepth(root->right);
    int leftD = getDepth(root->left);
    if(rightD == leftD) return root;
    if(rightD > leftD) return subtreeWithAllDeepest(root->right);
    else return subtreeWithAllDeepest(root->left);
}