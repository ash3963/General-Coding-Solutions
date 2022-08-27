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

void helper(TreeNode* root, string curr, vector<string>& answer) {
    if(!root) return;
    if(root->left || root->right) curr += to_string(root->val) + "->";
    else {
        curr += to_string(root->val);
        answer.push_back(curr);
    }
    helper(root->left, curr, answer);
    helper(root->right, curr, answer);
}


vector<string> binaryTreePaths(TreeNode* root) {
    string curr = "";
    vector<string> answer;
    helper(root, curr, answer);
    return answer;
}