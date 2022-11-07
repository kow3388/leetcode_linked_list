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

ListNode* rotateRight(ListNode *head, int k)
{
    if(!head)
        return nullptr;
    
    if(!head->next)
        return head;
    
    ListNode *tmp = head;
    int count = 1;
    while(tmp->next)
    {
        count++;
        tmp = tmp->next;
    }
    tmp->next = head;

    k = k % count;
    k = count - k;
    tmp = head;
    head = head->next;
    for(int i = 1; i < k; i++)
    {
        head = head->next;
        tmp = tmp->next;
    }
    tmp->next = nullptr;

    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(5);

    tmp = rotateRight(head, 2);
    while(tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}