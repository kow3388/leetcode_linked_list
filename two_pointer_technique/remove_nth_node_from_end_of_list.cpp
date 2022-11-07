#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode *head, int n)
{
    if(!head or !head->next)
        return nullptr;
    ListNode *l = head;
    ListNode *r = head;

    for(int i = 0; i < n; i++)
        r = r->next;
    
    if(!r)
    {
        head = head->next;
        delete l;
        return head;
    }

    while(r->next)
    {
        l = l->next;
        r = r->next;
    }
    ListNode *tmp = l->next;
    l->next = tmp->next;
    delete tmp;

    return head;
}

int main()
{
    int n = 2;   
    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(5);

    tmp = removeNthFromEnd(head, n);

    while(tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}