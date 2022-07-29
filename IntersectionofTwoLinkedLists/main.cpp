#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode{
    
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int nodeLength(ListNode* node){

    ListNode* temp=node;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){

    int l1=nodeLength(headA);
    int l2=nodeLength(headB);
    int d=0;
    ListNode* p1;
    ListNode* p2;
    if(l1>l2){
        d=l1-l2;
        p1=headA;
        p2=headB;
    }
    else{
        d=l2-l1;
        p1=headB;
        p2=headA;
    }
    while(d){
        p1=p1->next;
        if(p1==NULL)
            return NULL;
        d--;
    }
    while(p1!=NULL && p2!=NULL){
        if(p1==p2)
            return p1;
        p1=p1->next;
        p2=p2->next;
    }
    return NULL;
}


int main(){



    return 0;
}