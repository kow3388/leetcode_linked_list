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
        if(head == NULL or head->next == NULL)
            return head;
        else
        {
            ListNode *next_node = head->next;
            ListNode *prev_node = NULL;

            while(next_node != NULL)
            {
                head->next = prev_node;
                prev_node = head;
                head = next_node;
                next_node = head->next;
            }

            head->next = prev_node;

            return head;
        }
    }

bool isPalindrome(ListNode* head)
{
    if(!head or !head->next)
        return true;
    
    ListNode *fast = head, *slow = head;

    while(fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast)
        slow = slow->next;

    slow = reverseList(slow);

    for(; slow; slow = slow->next)
    {
        if(slow->val != head->val)
            return false;
        head = head->next;
    }

    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *tmp = new ListNode(2);
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = new ListNode(1);

    bool ans = isPalindrome(head);
    cout << ans << endl;

    return 0;
}