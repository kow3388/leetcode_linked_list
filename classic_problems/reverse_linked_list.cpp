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

ListNode* reverseList(ListNode *head)
{
    if(!head or !head->next)
        return head;
    
    ListNode *prev = NULL;
    ListNode *post = head->next;

    while(post)
    {
        head->next = prev;
        prev = head;
        head = post;
        post = post->next;
    }
    head->next = prev;

    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *tmp = new ListNode(2);
    head->next = tmp;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(5);

    tmp = reverseList(head);

    while(tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}