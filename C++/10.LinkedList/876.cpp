// middle of linked list
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

Node* middleLinkedList(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next!=NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

int main(){
    Node* head = new Node(5);
    insertionAtHead(head, 4);
    insertionAtHead(head, 6);
    insertionAtHead(head, 3);
    insertionAtHead(head, 2);
    insertionAtHead(head, 1);
    print(head);

    Node* ans = middleLinkedList(head);
    print(ans);

    return 0;
}