#include<iostream>
using namespace std;

class DoubleNode{
    public:
        DoubleNode* prev;
        int data;
        DoubleNode* next;

    DoubleNode(int data){
        this -> prev = NULL;
        this -> data = data;
        this -> next = NULL;
    }
};

void insertionAthead(DoubleNode* &head, DoubleNode* &tail, int data){
    DoubleNode* new_node = new DoubleNode(data);
    if(head == NULL){
        head = new_node;
        tail = new_node;
        return;
    }

    new_node -> next = head;
    head -> prev = new_node;
    head = new_node;
}

void insertionAttail(DoubleNode* &tail, DoubleNode* &head, int data){
    DoubleNode* new_node = new DoubleNode(data);
    if(tail == NULL){
        tail = new_node;
        head = new_node;
        return;
    }

    tail -> next = new_node;
    new_node -> prev = tail;
    tail = new_node;
}

void print(DoubleNode* &head){
    DoubleNode* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void reverseDLL(DoubleNode*& head, DoubleNode* curr, DoubleNode* prevnode){
    if(curr == NULL){
        return;
    }

    DoubleNode* forward = NULL;
    // DoubleNode* prevnode = NULL;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prevnode;
        curr -> prev = forward;
        prevnode = curr;
        curr = forward;
    }

    head = prevnode;
    return;
}


int main(){
    DoubleNode* head = NULL;
    DoubleNode* tail = head;
    insertionAthead(head, tail, 8);
    insertionAthead(head, tail, 16);
    insertionAthead(head, tail, 24);
    insertionAthead(head, tail, 64);
    insertionAthead(head, tail, 72);
    print(head);

    reverseDLL(head, head, NULL);
    print(head);
   
    return 0;
}