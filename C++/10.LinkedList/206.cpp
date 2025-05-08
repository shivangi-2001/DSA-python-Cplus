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

void insertionAtHead(Node* &head, int data){
    Node* new_node = new Node(data);
    new_node -> next = head;
    head = new_node;
}


void print(Node* & head){
    Node * temp = head;
    while(temp !=NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

// normal method - 1
Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;

    return head; 
}

// recursion method - 2;
void rr(Node*& head, Node* prev, Node* curr){
    if(curr == NULL){
        head = prev;
        return;
    }

    rr(head, curr, curr -> next);
    curr -> next = prev;
}
Node* reverseLL2(Node* head){
    Node* curr = head;
    Node* prev = NULL;

    rr(head, prev, curr);
    return head;
}

int main(){
    Node* head = new Node(5);
    insertionAtHead(head, 4);
    insertionAtHead(head, 3);
    insertionAtHead(head, 2);
    insertionAtHead(head, 1);
    print(head);

    Node* LL = reverseLL2(head);
    print(LL);
    return 0;
}