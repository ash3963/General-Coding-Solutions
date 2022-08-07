#include <iostream>
using namespace std;

struct ListNode {
    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    int c = 0;
    ListNode* newHead = new ListNode(0);
    ListNode* t = newHead;
    while(c || l1 || l2) {
        c += (l1? l1->val:0) + (l2? l2->val:0);
        t->next=new ListNode(c%10);
        c=c/10;
        t=t->next;
        if(l1)
            l1=l1->next;
        if(l2)
            l2=l2->next;
    }
    return newHead->next;
}