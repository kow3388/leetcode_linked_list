#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL){};
    Node(int v, Node *n): val(v), next(n){};
};

class MyLinkedList
{
    public:
        MyLinkedList()
        {
            head = NULL;
            len = -1;
        }
        int get(int index)
        {
            if(index > len)
                return -1;
            else
            {
                Node *tmp = head;
                int idx = 0;
                while(idx < index)
                {
                    tmp = tmp->next;
                    idx++;
                }

                return tmp->val;
            }
        }
        void addAtHead(int val)
        {
            Node *new_node = new Node(val, head);
            head = new_node;
            len++;
        }
        void addAtTail(int val)
        {
            Node *new_node = new Node(val);
            if(!head)
                head = new_node;
            else
            {
                Node *tmp = head;
                while(tmp->next)
                    tmp = tmp->next;
                tmp->next = new_node;
            }
            len++;
        }
        void addAtIndex(int index, int val)
        {
            if(index-1 > len)
                return;
            else
            {
                Node *new_node = new Node(val);
                int idx = 0;
                Node *tmp = head;
                while(idx < index-1)
                {
                    tmp = tmp->next;
                    idx++;
                }

                if(index == 0)
                {
                    new_node->next = head;
                    head = new_node;
                }
                else if(!tmp->next)
                    tmp->next = new_node;
                else
                {
                    new_node->next = tmp->next;
                    tmp->next = new_node;
                }

                len++;
            }
        }
        void deleteAtIndex(int index)
        {
            if(index > len or !head)
                return;
            if(index == 0)
            {
                Node *tmp = head;
                head = head->next;
                delete tmp;
            }
            else
            {
                Node *prev = head;
                Node *tmp;

                for(int i = 0; i < index-1; i++)
                    prev = prev->next;
                tmp = prev->next;
                prev->next = tmp->next;
                delete tmp;
            }
            len--;
        }
    private:
        Node *head;
        int len;
};

int main()
{
    MyLinkedList linked_list;
    linked_list.addAtHead(1);
    linked_list.addAtTail(3);
    linked_list.addAtIndex(1, 2);
    //linked_list.check();
    cout << linked_list.get(1) << endl;
    linked_list.deleteAtIndex(1);
    //linked_list.check();
    cout << linked_list.get(1) << endl;

    return 0;
}