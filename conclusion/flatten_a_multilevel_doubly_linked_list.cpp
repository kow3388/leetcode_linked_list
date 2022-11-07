#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int val;
        Node *prev;
        Node *next;
        Node *child;
        Node(int v)
        {
            val = v;
            prev = nullptr;
            next = nullptr;
            child = nullptr;
        }
        Node(int v, Node *pre)
        {
            val = v;
            prev = pre;
            next = nullptr;
            child = nullptr;
        }
};

Node* flatten1(Node *head)
{
    Node *tmp = head;

    while(tmp)
    {
        if(tmp->child)
        {
            Node *post = tmp->next;
            Node *ins = flatten1(tmp->child);
            tmp->next = ins;
            tmp->child = nullptr;
            ins->prev = tmp;
            while(tmp->next)
                tmp = tmp->next;
            tmp->next = post;
            if(post)
                post->prev = tmp;
        }
        tmp = tmp->next;
    }

    return head;
}

//網路上其他人的做法
//純recursive
Node* flatten(Node *head, Node *rest = nullptr)
{
    if(!head)
        return rest;
    
    //從後面開始flatten在把她接到child list後面
    head->next = flatten(head->child, flatten(head->next, rest));

    if(head->next)
        head->next->prev = head;
    
    head->child = nullptr;

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *tmp = head;
    tmp->next = new Node(2, tmp);
    tmp = tmp->next;
    tmp->next = new Node(3, tmp);
    tmp = tmp->next;
    tmp->child = new Node(7);
    Node *c = tmp->child;
    tmp->next = new Node(4, tmp);
    tmp = tmp->next;
    tmp->next = new Node(5, tmp);
    tmp = tmp->next;
    tmp->next = new Node(6, tmp);
    tmp = c;
    tmp->next = new Node(8, tmp);
    tmp = tmp->next;
    tmp->child = new Node(11);
    c = tmp->child;
    tmp->next = new Node(9, tmp);
    tmp = tmp->next;
    tmp->next = new Node(10, tmp);
    tmp = c;
    tmp->next = new Node(12, tmp);

    tmp = flatten(head);

    while(tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}