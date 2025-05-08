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


bool hasCycle(Node *head) {
    if (head == nullptr || head->next == nullptr) return false;
    if (head->next == head) return true;
    Node* fast = head;
    Node* slow = head;

    while (fast != nullptr && fast->next != nullptr && slow != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) return true;
    }

    return false;
}


int main(){
    Node* tail = new Node(5);
    insertAtTail(tail, 10, 5);
    insertAtTail(tail, 20, 10);
    insertAtTail(tail, 40, 20);
    insertAtTail(tail, 30, 20);
    print(tail);


    return 0;
}