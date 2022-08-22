#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) {
    vector<int> v;
    helper(v, root);
    return v[k-1];
}
void helper(vector<int>& v, TreeNode* root) {
    if(root->left) helper(v, root->left);
    v.push_back(root->val);
    if(root->right) helper(v, root->right);
}