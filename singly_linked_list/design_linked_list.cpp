#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(): val(0), next(NULL){};
    Node(int v): val(v), next(NULL){};
};

class MyLinkedList1
{
    public:
        MyLinkedList1()
        {
            head = NULL;
        }

        int get(int index)
        {
            if(!head)
                return -1;
            Node *tmp = head;
            int cnt = 0;
            while(tmp->next and cnt < index)
            {
                tmp = tmp->next;
                cnt++;
            }

            return cnt == index? tmp->val : -1;
        }

        void addAtHead(int val)
        {
            Node *add_node = new Node(val);
            if(!head)
                head = add_node;
            else
            {
                add_node->next = head;
                head = add_node;
            }
        }
        
        void addAtTail(int val)
        {
            Node *add_node = new Node(val);
            if(!head)
                head = add_node;
            else
            {
                Node *tmp = head;
                while(tmp->next)
                    tmp = tmp->next;
                tmp->next = add_node;
            }
        }
        
        void addAtIndex(int index, int val)
        {
            Node *add_node = new Node(val);
            int cnt = 0;
            if(!head and index == 0)
                head = add_node;
            else if(!head and index != 0)
                return;
            else if(index == 0)
            {
                add_node->next = head;
                head = add_node;
            }
            else
            {
                Node *tmp = head;
                while(tmp->next and cnt < index-1)
                {
                    tmp = tmp->next;
                    cnt++;
                }
                if(cnt == index-1)
                {
                    add_node->next = tmp->next;
                    tmp->next = add_node;
                }
                else
                    return;
            }
        }
        
        void deleteAtIndex(int index)
        {
            if(index == 0)
            {
                Node *tmp = head;
                head = head->next;
                delete tmp;
            }
            else
            {
                Node *prev = head;
                int cnt = 0;

                while(prev->next and cnt < index-1)
                {
                    prev = prev->next;
                    cnt++;
                }
                if(cnt == index-1 and prev->next)
                {
                    Node *tmp = prev->next;
                    prev->next = tmp->next;
                    delete tmp;
                }
                else
                    return;
            }
        }
        void check()
        {
            Node *tmp = head;
            while(tmp)
            {
                cout << tmp->val << endl;
                tmp = tmp->next;
            }
        }
    private:
        Node *head;
};

//官方解答在private時多設置一個int size
//在後續可以省去很多index判斷
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
            if(index > len or !head)
                return -1;
            else
            {
                Node *tmp = head;
                for(int i = 0; i < index; i++)
                    tmp = tmp->next;
                
                return tmp->val;
            }
        }
        void addAtHead(int val)
        {
            Node *n = new Node(val);
            if(!head)
                head = n;
            else
            {
                n->next = head;
                head = n;
            }
            len++;
        }
        void addAtTail(int val)
        {
            Node *n = new Node(val);
            if(!head)
                head = n;
            else
            {
                Node *tmp = head;
                while(tmp->next)
                    tmp = tmp->next;
                tmp->next = n;
            }
            len++;
        }
        void addAtIndex(int index, int val)
        {
            if(index > len+1)
                return;
            else if(index == 0)
            {
                addAtHead(val);
                return;
            }
            else
            {
                Node *n = new Node(val);
                Node *tmp = head;

                for(int i = 0; i < index-1; i++)
                    tmp = tmp->next;
                
                n->next = tmp->next;
                tmp->next = n;
            }
            len++;
        }
        void deleteAtIndex(int index)
        {
            if(index > len or !head)
                return;
            if(head and index == 0)
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