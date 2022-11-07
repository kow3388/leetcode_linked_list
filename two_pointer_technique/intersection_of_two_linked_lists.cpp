#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(vector<int> nums)
{
    ListNode dummy(0);
    ListNode *head = &dummy;

    for(int i = 0; i < nums.size(); i++)
    {
        head->next = new ListNode(nums[i]);
        head = head->next;
    }

    return dummy.next;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(!headA or !headB)
        return nullptr;
    ListNode *a = headA;
    ListNode *b = headB;

    while(a != b)
    {
        a = (a == NULL)? headB : a->next;
        b = (b == NULL)? headA : b->next;
    }

    return a;
}

int main()
{
    vector<int> nums = {4,1};
    ListNode *headA = createList(nums);

    nums = {5, 6, 1};
    ListNode *headB = createList(nums);

    nums = {8, 4, 5};
    ListNode *headC = createList(nums);

    ListNode *tmp = headA;

    while(tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = headC;

    tmp = headB;

    while(tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = headC;

    ListNode *ans = getIntersectionNode(headA, headB);
    while(ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}