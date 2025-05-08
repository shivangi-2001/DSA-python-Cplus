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

Node* reverseBygroup(Node* head, int k){
    // base case
    if(head == NULL || head -> next == NULL){
        return head;
    }

    // step 1: solve 1 case
    // count the nodes < k or not
    // if yes then reverse else return head
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;

    Node* temp = head;
    int remain = 0;
    while(remain < k && temp != NULL){
        temp = temp -> next;
        remain++;
    }

    if(remain < k){
        return head;
    }

    while(count < k && curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    head -> next = reverseBygroup(forward, k);

    return prev;
}

int main(){
    Node* head = new Node(5);
    insertionAtHead(head, 4);
    insertionAtHead(head, 3);
    insertionAtHead(head, 2);
    insertionAtHead(head, 1);
    print(head);

    int k= 1;
    Node* ll = reverseBygroup(head, k);

    print(ll);

    return 0;
}