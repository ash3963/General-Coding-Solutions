#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;



class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int key, int val) {
                this->key = key;
                this->val = val;
                next = NULL;
                prev = NULL;
            }
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node* currNode) {
        currNode->next = head->next;
        head->next->prev = currNode;
        head->next = currNode;
        currNode->prev = head;
        mp[currNode->key] = currNode;
    }

    void remove(Node* currNode) {
        mp.erase(currNode->key);
        currNode->next->prev = currNode->prev;
        currNode->prev->next = currNode->next;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        Node* currnode = mp[key];
        remove(currnode);
        insert(currnode);
        return currnode->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
            remove(mp[key]);
        if(mp.size() == capacity)
            remove(tail->prev);
        insert(new Node(key, value));
    }
};