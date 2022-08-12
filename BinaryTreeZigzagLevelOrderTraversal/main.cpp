#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> result;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()) {
        vector<int> curr;
        int n = q.size();
        for(int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            if(leftToRight) curr.push_back(node->val);
            else curr.insert(curr.begin(), node->val);
        }
        result.push_back(curr);
        leftToRight = !leftToRight;
    }
    return result;
}