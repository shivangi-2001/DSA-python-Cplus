#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};

void insert(Node* &head, int data){
    Node* newnode = new Node(data);
    if(head == NULL){
        head = newnode;
        head -> next = head;
        return;
    }

    Node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }

    temp -> next = newnode;
    newnode -> next  = head;
    return;
}

void print(Node*& head){
    Node* temp = head;

    while(temp -> next != head){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << temp -> data ;
    cout << endl;
}

void deleteNode(Node* & head, int ele){
    Node* prev = NULL;
    Node* temp = head;

    while(temp -> data != ele){
        prev = temp;
        temp = temp -> next;
    }

    if(temp == head){
        Node* last = temp;

        while(last->next != temp){
            last = last -> next;
        }

        last -> next = head -> next;
        head = head->next;
        return;
    }

    prev ->next = temp -> next;
    delete temp;
}

int main(){
    Node* head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    insert(head, 50);
    insert(head, 60);

    print(head);

    deleteNode(head, 40);
    print(head);

    deleteNode(head, 20);
    print(head);

    deleteNode(head, 10);
    print(head);
    return 0;
}