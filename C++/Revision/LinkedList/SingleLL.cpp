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

void insertAtHead(Node*& head, int data){
    if(head == NULL) {
        head = new Node(data);
    }
    else {
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }
};

void insertAtTail(Node*& tail, int data){
        Node* temp = new Node(data);
        tail -> next = temp;
        tail = temp;
};

void print(Node*& head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout<< endl;
}

int lengthLL(Node*& head){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

void insertAtMiddle(Node*& head, Node*& tail, int pos, int data){
    int idx = 0;
    if(pos == 0){
        insertAtHead(head, data);
        return;
    }
    
    int length = lengthLL(head);
    if(pos >= length) return;

    if(pos > length){
        insertAtTail(tail, data);
        return;
    }
    Node* curr = head;
    Node* prev = NULL;

    while(idx != pos){
        prev = curr;
        curr = curr -> next;
        idx++;
    }

    Node* temp = new Node(data);
    prev ->next = temp;
    temp -> next = curr;
}

void deleteAtIndex(Node*& head, Node*& tail, int index){
    if (index == 1){
        head = head -> next;
        return;
    }

    int l = lengthLL(head);

    int count = 1;
    Node* prev = NULL;
    Node* temp = head;
    while(count != index){
        prev = temp;
        temp = temp -> next;
        count++;
    }

    prev -> next = temp -> next;

    if(index==l) tail = prev;

}

int main(){
    Node* head = new Node(5);
    Node* tail = head;

    insertAtHead(head, -10);
    insertAtHead(head, -15);
    insertAtHead(head, -20);
    insertAtHead(head, -25);
    insertAtHead(head, -30);

    print(head);

    insertAtTail(tail, 10);
    insertAtTail(tail, 15);
    insertAtTail(tail, 20);
    insertAtTail(tail, 25);
    insertAtTail(tail, 30);

    print(head);

    cout << "length of the linked list: " << lengthLL(head) << endl;


    cout << "Insert at pos = 1: " ;
    insertAtMiddle(head, tail, 1, -1000);
    print(head);

    cout << "Insert at pos = 2: " ;
    insertAtMiddle(head, tail, 2, -2000);
    print(head);


    cout << "Insert at pos = 100: " ;
    insertAtMiddle(head, tail, 100, -2000);
    print(head);

    cout << "Insert at pos = 10: " ;
    insertAtMiddle(head, tail, 10, 2000);
    print(head);

    cout << "Insert at pos = 13: " ;
    insertAtMiddle(head, tail, 13, 10000);
    print(head);

    cout << "delete at index = 1: " ;
    deleteAtIndex(head, tail, 1);
    print(head);

    cout << "delete at index = 3: " ;
    deleteAtIndex(head, tail, 3);
    print(head);

    cout << "delete at index = 10: " ;
    deleteAtIndex(head, tail, 10);
    print(head);

    cout << "length of the linked list: " << lengthLL(head) << endl;


    cout << "delete at index = 12: " ;
    deleteAtIndex(head, tail, 12);
    print(head);

    return 0;
}