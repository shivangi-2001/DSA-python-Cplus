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

int getLength(DoubleNode* &head){
    int len = 0;
    DoubleNode* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertionAtmiddle(DoubleNode* &head, DoubleNode* &tail, int index, int data){
    DoubleNode* new_node = new DoubleNode(data);
    if(index <= 0){
        return;
    }

    if(index == 1){
        insertionAthead(head, tail, data);
        return;
    }

    int len = getLength(head);
    if(index == len){
        insertionAttail(tail, head, data);
        return;
    }

    int count = 1;
    DoubleNode* temp = head;
    while(count < index-1){
        temp = temp -> next;
        count++;
    }

    new_node -> next = temp -> next;
    temp ->next -> prev = new_node;
    temp -> next = new_node;
    new_node -> prev = temp;

    if(temp -> next == NULL){
        new_node -> prev = temp;
        temp -> next = new_node;
    }

}

void deleteAtindex(DoubleNode* &head, DoubleNode* &tail, int index){
    if(index <= 0) return;
    if (index == 1){
        head -> next -> prev = NULL;
        head = head -> next;
        return;
    }
    int len = getLength(head);
    if(index == len){
        tail -> prev -> next = NULL;
        tail = tail -> prev;
        return;
    }

    int count = 1;
    DoubleNode* temp = head;
    while(count < index){
        temp = temp -> next;
        count++;
    }

    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;

    delete temp;
}

int main(){
    DoubleNode* head = NULL;
    DoubleNode* tail = head;
    insertionAthead(head, tail, 8);
    insertionAthead(head, tail, 16);
    insertionAthead(head, tail, 24);
    print(head);
    int len = getLength(head);
    cout << "length: " << len << endl;
    insertionAttail(tail, head, 72);
    insertionAttail(tail, head, 80);
    print(head);

    insertionAtmiddle(head, tail, 3, -8);
    print(head);
    insertionAtmiddle(head, tail, 6, 64);
    print(head);

    deleteAtindex(head, tail, 7);
    print(head);
    deleteAtindex(head, tail, 1);
    print(head);

    deleteAtindex(head, tail, 3);
    print(head);
    return 0;
}