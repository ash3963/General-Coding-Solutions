#include <iostream>
#include <vector>
#include <stack>
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

vector<int> postorderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);
    while(stk.size()) {
        TreeNode* curr = stk.top();
        if(curr->left) {
            stk.push(curr->left);
            curr->left = NULL;
        }
        else {
            if(curr->right) {
                stk.push(curr->right);
                curr->right = NULL;
            }
            else {
                result.push_back(curr->val);
                stk.pop();
            }
        }
    }
    return result;
}