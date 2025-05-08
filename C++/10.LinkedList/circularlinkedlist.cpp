#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &tail, int data, int ele){
    Node* new_node = new Node(data);
    if(tail == NULL){
        tail = new_node;
        tail -> next = tail;
    }else{
        Node* temp = tail;
        while(temp -> data != ele){
            temp = temp -> next;
        }
        new_node -> next = temp -> next;
        temp -> next = new_node;
    }
}

void print(Node* &head){
    Node* temp = head;
    do {
        cout << temp ->data << " ";
        temp = temp -> next;
    }while(temp!=head);
    cout << endl;
}

void deleteAtTail(Node* &tail, int ele){
    Node* prev = tail;
    Node* temp = prev -> next;
    while(temp -> data != ele){
        prev = temp;
        temp = temp ->next;
    }
    if(temp == tail){
        prev -> next = tail -> next;
        tail = prev;
        return;
    }
    prev -> next = temp -> next;
    delete temp;
    return;
}



int main(){
    Node* tail = NULL;
    insertAtTail(tail, 10, 0);
    insertAtTail(tail, 20, 10);
    insertAtTail(tail, 40, 20);
    insertAtTail(tail, 30, 20);
    print(tail);

    deleteAtTail(tail, 30);
    print(tail);
    deleteAtTail(tail, 10);
    print(tail);
    return 0;
}