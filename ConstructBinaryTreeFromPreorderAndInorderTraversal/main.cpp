#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& idx, int start, int end){
    if(start > end) return NULL;
    int pivot = start;
    while(inorder[pivot] != preorder[idx]) pivot++;
    idx++;
    TreeNode* node = new TreeNode(inorder[pivot]);
    node->left = helper(preorder, inorder, idx, start, pivot-1);
    node->right = helper(preorder, inorder, idx, pivot+1, end);
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int idx = 0;
    return helper(preorder, inorder, idx, 0, preorder.size()-1);
}