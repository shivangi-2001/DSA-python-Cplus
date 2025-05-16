#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node*& head, Node*& tail, int data){
    Node* newnode = new Node(data);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertionSort(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* dummy = new Node(-1);
    dummy -> next = head;

    Node* curr = head->next;
    Node* prev = head;

    while(curr){
        if(curr -> data >= prev -> data){
            prev = prev -> next;
            curr = curr -> next;
            continue;
        }

        Node* temp = dummy;
        while(curr -> data > temp-> next -> data){
            temp = temp -> next;
        }

        prev -> next = curr -> next;
        curr -> next = temp -> next;
        temp -> next = curr;
        curr = prev -> next; 
    }

    return dummy -> next;
}

int main(){
    Node* head = NULL;
    Node* tail = head;

    insertAtTail(head, tail, -1);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 0);

    cout << "Original List: ";
    print(head);

    Node* ans = insertionSort(head);

    cout << "Sorted List: ";
    print(ans);
}