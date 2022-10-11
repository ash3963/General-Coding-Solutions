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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    TreeNode* temp;
    while(root) {
        if(root->left) {
            temp = root->left;
            while(temp->right != NULL)
                temp = temp->right;
            temp->right = root;
            temp = root->left;
            root->left = NULL;
            root = temp;
        }
        else {
            result.push_back(root->val);
            root = root->right;
        }
    }
    return result;
}
