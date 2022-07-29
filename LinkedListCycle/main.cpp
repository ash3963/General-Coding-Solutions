#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {

    if(head == NULL)
        return false;

    ListNode* fp=head;
    ListNode* sp=head;

    while(fp!=NULL&&fp->next!=NULL){
        fp=fp->next->next;
        sp=sp->next;
        if(fp==sp){
            return 1;
        }
    }
    return 0;
}

int main(){




    return 0;
}