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

Node* reverseBetween(Node* head, int left, int right){
    // single node
    if(left == right){
        return head;
    }

    Node* leftmost = NULL;
    Node* leftnode = head;
    int leftcount = 1;

    while(leftcount < left){
        leftmost = leftnode;
        leftnode = leftnode -> next;
        leftcount++;
    }

    Node* rightmost = head->next;
    Node* rightnode = head;
    int rightcount = 1;

    while(rightcount < right){
        rightmost = rightmost -> next;
        rightnode = rightnode -> next;
        rightcount++;
    }

    // cout << leftmost -> data <<  endl;
    // cout << leftnode -> data <<  endl;
    // cout << rightnode -> data <<  endl;
    // cout << rightmost -> data <<  endl;

    Node* forward = NULL;
    Node* prev = rightmost;

    while(leftnode != prev){
        forward = leftnode -> next;
        leftnode -> next = rightmost;
        rightmost = leftnode;
        leftnode = forward;
    }

    if(leftmost != NULL) head -> next = rightnode;
    if(leftmost == NULL) head = rightnode;
    return head;
}


int main(){
    Node* head = new Node(5);
    insertionAtHead(head, 4);
    insertionAtHead(head, 3);
    insertionAtHead(head, 2);
    insertionAtHead(head, 1);
    print(head);

    int left = 1;
    int right = 4;

    Node* ans = reverseBetween(head, left, right);
    print(ans);

    return 0;
}