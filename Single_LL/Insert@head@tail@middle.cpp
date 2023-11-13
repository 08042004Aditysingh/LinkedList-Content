#include<bits/stdc++.h>
using namespace std;

//Unidirectional Linked List, a head pointer and a tail pointer is used to keep track of the linked list.
//A Null pointer is used to mark the end of the linked list.


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this ->next = NULL;
    };

};
void insertAtHead(Node* &head,int data){
    Node* node1 = new Node(data);
    node1->next=head;
    head = node1;
};
void insertAtTail(Node* &tail,int data){
    Node* node1 = new Node(data);
    tail->next = node1;
    tail = node1;

};
void insertAtMiddle(Node* &tail,Node* &head,int data,int pos){
    Node* node1 = new Node(data);
    Node* temp = head;
    if(pos == 1){
        insertAtHead(head,data);
        return;
    }
    for(int i =1;i<pos-1;i++){
        temp = temp->next;
    };
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }
    node1->next = temp->next;
    temp->next = node1;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
};
int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtMiddle(tail,head,5,8);
    print(head);
    return 0;
}