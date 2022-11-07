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

ListNode* oddEvenList1(ListNode *head)
{
    if(!head or !head->next)
        return head;

    ListNode *odd_head = head, *odd_tail = odd_head;
    ListNode *even_head = head->next, *even_tail = even_head;
    head = even_head->next;
    int idx = 1;

    while(head)
    {
        if(idx%2 != 0)
        {
            odd_tail->next = head;
            odd_tail = head;
        }
        else
        {
            even_tail->next = head;
            even_tail = head;
        }
        head = head->next;
        idx++;
    }

    odd_tail->next = even_head;
    even_tail->next = nullptr;

    return odd_head;
}

//網路上其他人的寫法，一次跨兩格
ListNode* oddEvenList(ListNode *head)
{
    if(!head or !head->next)
        return head;
    
    ListNode *odd = head;
    ListNode *even_head = head->next, *even_tail = even_head;

    while(odd->next and even_tail->next)
    {
        odd->next = even_tail->next;
        even_tail->next = odd->next->next;
        odd = odd->next;
        even_tail = even_tail->next;
    }
    odd->next = even_head;

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

    tmp = oddEvenList(head);
    while(tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}