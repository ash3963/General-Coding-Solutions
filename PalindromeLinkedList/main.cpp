#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head){
    
    ListNode* fast=head;
    ListNode* slow=head;
    ListNode  *prev,*temp; 
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    prev=slow;slow=slow->next;prev->next=NULL;
    while(slow){
        temp=slow->next;
        slow->next=prev;
        prev=slow;
        slow=temp;
    }
    fast=head; slow=prev;
    while(slow){
        if(fast->val!=slow->val)
            return false;
        fast=fast->next;
        slow=slow->next;
    }
    return true;
}