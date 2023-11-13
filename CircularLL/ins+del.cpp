#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = next;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertValue(Node *&tail, int ele, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        temp->next = temp;
        tail = temp;
    }
    else
    {
        Node *node1 = new Node(data);
        Node *temp = tail;
        while (temp->data != ele)
        {
            temp = temp->next;
        }
        node1->next = temp->next;
        temp->next = node1;
    }
};

void print(Node *&tail)
{
    Node *temp = tail->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
};

void deleteValue(Node *&tail, int val)
{
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    };
    prev->next = curr->next;
    if (tail == curr)
    {
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}
int main()
{
    Node *tail = NULL;

    insertValue(tail, 0, 1);
    insertValue(tail, 1, 2);
    insertValue(tail, 2, 3);
    print(tail);
    deleteValue(tail, 1);
    print(tail);
}
