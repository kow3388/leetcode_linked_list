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

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode();
    ListNode *head = dummy;
    int sum = 0;

    while(l1 or l2 or sum)
    {
        sum += (l1? l1->val:0) + (l2? l2->val:0);
        l1 = l1? l1->next:NULL;
        l2 = l2? l2->next:NULL;
        head->next = new ListNode(sum % 10);

        sum /= 10;
        head = head->next;
    }

    return dummy->next;
}

int main()
{
    ListNode *head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);

    ListNode *tmp = addTwoNumbers(head1, head2);

    while(tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}