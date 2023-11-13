#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        };
    }
};
void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
};
int printLen(Node* &head)
{
    int len = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
};

void insertAtHead(Node* &tail,Node* &head, int data){
    if(head ==NULL){
        Node* node1 = new Node(data);
        head = node1;
        tail = node1;

    }
    else{Node* node1 = new Node(data);
    node1->next = head;
    head->prev = node1;
    head = node1;}

};
void insertAtTail(Node* &tail,Node* &head,int data){

    if(head ==NULL){
        Node* node1 = new Node(data);
        head = node1;
        tail = node1;

    }
    else{
    Node* node1=new Node(data);
    tail->next = node1;
    node1->prev = tail;
    tail = node1;
    };
    
};
void insertAtMiddle(Node* &tail,Node* &head,int data,int pos){
    if(pos ==1){
        insertAtHead(tail,head,data);
        return;
    }
    Node* node1 = new Node(data);
    Node* temp = head;
    for(int i =1;i<pos-1;i++){
        temp = temp->next;
    };
    if(temp->next == NULL){
        insertAtTail(tail,head,data);
        return;
    };
    node1->next = temp->next;
    temp->next->prev = node1;
    temp->next = node1;
    node1->prev = temp;
};
void deleteNode(Node* &tail,Node* &head,int data,int pos){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head ->prev = NULL;

        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        for(int i =1;i<pos;i++){
            prev = curr;
            curr = curr->next;
        };
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
        if(prev->next == NULL){
            tail = prev;
        }

    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(tail,head,1);
    cout<<head->data<<tail->data<<endl;
    insertAtHead(tail,head,3);
    cout<<head->data<<tail->data<<endl;
    insertAtHead(tail,head,4);
    cout<<head->data<<tail->data<<endl;
    insertAtHead(tail,head,5);
    cout<<head->data<<tail->data<<endl;
    insertAtTail(tail,head,2);
    cout<<head->data<<tail->data<<endl;
    insertAtMiddle(tail,head,3,1);
    cout<<head->data<<tail->data<<endl;
    print(head);
    cout<<endl;
    deleteNode(tail,head,3,1);
    print(head);


    cout<<endl<<printLen(head);



}