#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//想不到, 第一種方法用hash set
ListNode* detectCycle1(ListNode *head)
{
    unordered_set<ListNode*> s;
    ListNode *tmp = head;
    while(tmp)
    {
        if(s.count(tmp))
            return tmp;
        s.insert(tmp);
        tmp = tmp->next;
    }

    return nullptr;
}

//龜兔賽跑演算法
ListNode* detectCycle(ListNode *head)
{
    if(!head or !head->next)
        return nullptr;
    ListNode *fast = head->next->next;
    ListNode *slow = head->next;

    while(fast and fast->next)
    {
        if(fast == slow)
            break;
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast != slow)
        return nullptr;
    slow = head;

    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
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

    ListNode *ans = detectCycle(head);
    cout << ans->val << endl;

    return 0;
}