#include<bits/stdc++.h>
using namespace std;

//Declaration of a Node class and using new operator to create a node dynamically and printing the address of the node and the data stored in it.
class Node{

    public:
    int data;
    Node* next;

    public:
    Node(int data){
        this->data = data;
        this ->next = NULL;
    }
};
int main(){

    Node* ptr = new Node(10);

    cout<<ptr->data<<endl<<ptr->next<<endl<<ptr<<endl;



}