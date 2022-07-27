#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    ListNode *p1 = list1;
    ListNode *p2 = list2;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *p3 = dummyNode;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val < p2->val)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
     while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummyNode->next;
}

void display(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{

    ListNode *h1 = new ListNode(1);
    ListNode *s1 = new ListNode(4);
    ListNode *t1 = new ListNode(5);
    ListNode *f1 = new ListNode(7);

    ListNode *h2 = new ListNode(2);
    ListNode *s2 = new ListNode(3);
    ListNode *t2 = new ListNode(6);

    h1->next = s1;
    s1->next = t1;
    t1->next = f1;

    h2->next = s2;
    s2->next = t2;

    cout<<"l1: ";
    display(h1);
    cout<<"l2: ";
    display(h2);

    ListNode *h3 = mergeTwoLists(h1, h2);


    cout<<"Merged List: ";
    display(h3);

    

    return 0;
}