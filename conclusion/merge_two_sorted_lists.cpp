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

ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if(!list1 and !list2)
        return nullptr;
    else if(!list1 and list2)
        return list2;
    else if(list1 and !list2)
        return list1;
    else
    {
        ListNode *head, *tmp;
        ListNode *l1 = list1;
        ListNode *l2 = list2;
        if(list1->val < list2->val)
        {
            head = l1;
            tmp = head;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            tmp = head;
            l2 = l2->next;
        }

        while(l1 or l2)
        {
            if(!l1)
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            else if(!l2)
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            else
                if(l1->val < l2->val)
                {
                    tmp->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    tmp->next = l2;
                    l2 = l2->next;
                }
            tmp = tmp->next;
        }

        return head;
    }
}

int main()
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode *tmp = mergeTwoLists(head1, head2);
    while(tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}