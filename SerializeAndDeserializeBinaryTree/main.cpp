#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    
    void buildString(TreeNode* root, string& res) {
        if(!root){
            res += "null,";
            return;
        }
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }

    string serialize(TreeNode *root) {
        string res = "";
        buildString(root, res);
        return res;
    }

    TreeNode* buildTree(queue<string>& q) {
        string s = q.front();
        q.pop();
        if(s == "null")
            return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }

    TreeNode *deserialize(string data) {
        string temp;
        queue<string> q;
        for(char d : data) {
            if(d == ',') {
                q.push(temp);
                temp = "";
            }
            else temp += d;
        }
        return buildTree(q);
    }
};