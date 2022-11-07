#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements1(ListNode *head, int val)
{
    if(!head)
        return nullptr;
    
    while(head and head->val == val)
    {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
    }

    if(!head)
        return nullptr;

    ListNode *prev = head;
    ListNode *curr = head->next;

    while(curr)
    {
        if(curr->val == val)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }

    return head;
}

//網路上其他人的精簡寫法
ListNode* removeElements(ListNode *head, int val)
{
    ListNode *dummy = new ListNode(-1, head);
    ListNode *prev = dummy;

    for(; head; head = head->next)
    {
        if(head->val == val)
        {
            prev->next = head->next;
            delete head;
            head = prev;
        }
        else
            prev = prev->next;
    }

    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *tmp = new ListNode(2);
    head->next = tmp;
    tmp->next = new ListNode(6);
    tmp = tmp->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(5);
    tmp = tmp->next;
    tmp->next = new ListNode(6);
    int val = 6;

    tmp = removeElements(head, val);
    while(tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}