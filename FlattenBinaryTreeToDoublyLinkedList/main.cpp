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

void flattenHelper(TreeNode* root, TreeNode* prev, TreeNode* head) {
    if(!root) return;
    flattenHelper(root->left, prev, head);
    if(!prev) 
        head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    flattenHelper(root->right, prev, head);
}

void flatten(TreeNode* root) {
    TreeNode* prev = NULL;
    TreeNode* head = NULL;
    flattenHelper(root, prev, head);
}