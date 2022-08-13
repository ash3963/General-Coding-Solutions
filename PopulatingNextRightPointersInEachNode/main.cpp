#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


Node* connect(Node* root) {
    if(!root) return NULL;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* rightNode = NULL;
        int n = q.size();
        for(int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            curr->next = rightNode;
            rightNode = curr;
            if(curr->right) {
                q.push(curr->right);
                q.push(curr->left);
            }
        }
    }
    return root;   
}