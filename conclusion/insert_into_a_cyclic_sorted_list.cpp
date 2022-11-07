#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int val;
        Node* next;

        Node(){}
        Node(int _val)
        {
            val = _val;
            next = NULL;
        }
        Node(int _val, Node* _next)
        {
            val = _val;
            next = _next;
        }
};

Node* insert(Node *head, int v)
{
    Node *ins = new Node(v);

    if(!head)
    {
        ins->next = ins;
        return ins;
    }
    if(head->val == v)
    {
        ins->next = head->next;
        head->next = ins;

        return head;
    }

    Node *tmp = head;

    while(true)
    {
        if((tmp->val < v and v <= tmp->next->val) or
           (tmp->val > tmp->next->val and (v <= tmp->next->val or v > head->val)) or
           (tmp->val != head->val and tmp->next->val == head->val) or
           (tmp->val == head->val and tmp->next == head))
        {
            ins->next = tmp->next;
            tmp->next = ins;
            break;
        }
        tmp = tmp->next;
    }

    return head;
}

int main()
{
    Node *head = new Node(3);
    Node *tmp = head;
    tmp->next = new Node(4);
    tmp = tmp->next;
    tmp->next = new Node(1);
    tmp = tmp->next;
    tmp->next = head;

    tmp = insert(head, 2);
    for(int i = 0; i < 4; i++)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}