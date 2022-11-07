#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if(!head or !head->next)
        return false;
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    };

    return false;
}

int main()
{
    ListNode *head = new ListNode(3);
    ListNode *tmp = head;
    ListNode *pos = new ListNode(2);
    tmp->next = pos;
    tmp = tmp->next;
    tmp->next = new ListNode(0);
    tmp = tmp->next;
    tmp->next = new ListNode(-4);
    tmp = tmp->next;
    tmp->next = pos;

    bool ans = hasCycle(head);
    cout << ans << endl;

    return 0;
}