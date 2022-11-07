#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int val;
        Node *next;
        Node *random;
        
        Node(int _val)
        {
            val = _val;
            next = NULL;
            random = NULL;
        }
};

//我只想到brute force
//Time: O(n^2), Space: O(1)
//此方法用hash table
//Time: O(n), Space: O(n)
Node* copyRandomList(Node *head)
{
    if(!head)
        return nullptr;
    
    unordered_map<Node*, Node*> m;
    Node *new_head = new Node(head->val);
    Node *tmp = new_head;
    m.emplace(head, new_head);

    while(head)
    {
        if(head->random)
        {
            auto it = m.find(head->random);
            if(it == m.end())
                m.emplace(head->random, new Node(head->random->val));
            tmp->random = m[head->random];
        }

        if(head->next)
        {
            auto it = m.find(head->next);
            if(it == m.end())
                m.emplace(head->next, new Node(head->next->val));
            tmp->next = m[head->next];
        }

        tmp = tmp->next;
        head = head->next;
    }

    return new_head;
}

int main()
{
    Node *head = new Node(7);
    Node *tmp = head;
    tmp->next = new Node(13);
    tmp->next->next = new Node(11);
    tmp->next->next->next = new Node(10);
    tmp->next->next->next->next = new Node(1);
    tmp->next->random = tmp;
    tmp->next->next->random = tmp->next->next->next->next;
    tmp->next->next->next->random = tmp->next->next;
    tmp->next->next->next->next->random = tmp;

    tmp = copyRandomList(head);

    return 0;
}