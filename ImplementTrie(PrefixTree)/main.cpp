#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Trie {
    vector<Trie*> children;
    int prefixCount, leafCount;
public:
    Trie() {
        this->children.resize(26, NULL);
        this->prefixCount = 0;
        this->leafCount = 0;
    }
    
    void insert(string word) {
        if(word.empty()) return;
        Trie* root = this;
        root->prefixCount++;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(root->children[index] == NULL) {
                root->children[index] = new Trie();
            }
            root = root->children[index];
            root->prefixCount++;
        }
        root->leafCount++;
    }
    
    bool search(string word) {
        if(word.empty() || !this) return false;
        Trie* root = this;
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            root = root->children[index];
            if(!root) return false;
        }
        if(root->leafCount > 0) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        if(prefix.empty() || !this) return false;
        Trie* root = this;
        for(int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            root = root->children[index];
            if(!root) return false;
        }
        if(root->prefixCount > 0) return true;
        return false;
    }
};