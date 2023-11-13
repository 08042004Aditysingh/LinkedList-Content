#include<bits/stdc++.h>
using namespace std;



class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this ->next = NULL;
    };

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        };
        cout<<"List is free with value "<<value<<endl;

    }

    

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
};

void deleteNode(Node* &tail,Node* &head,int pos){
    if(pos==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;


    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        for(int i = 1;i<pos;i++){
            prev = curr;
            curr = curr->next;
        };
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        if(prev->next == NULL){
            tail = prev;
        }

    }
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
    deleteNode(tail,head,3);
    print(head);
    deleteNode(tail,head,1);
    deleteNode(tail,head,6);
    cout<<endl<<head->data<<endl;
    cout<<tail->data<<endl;
    return 0;
}