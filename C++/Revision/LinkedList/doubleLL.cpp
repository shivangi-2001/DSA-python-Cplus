#include<iostream>
using namespace std;

class DoubleLL{
    public:
    int data;
    DoubleLL* prev = NULL;
    DoubleLL* next = NULL;

    DoubleLL(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void print(DoubleLL *& head){
    DoubleLL* temp = head;

    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp -> next;
    }

    cout << endl;
}

void insert(DoubleLL*& head, int data, int pos){
    DoubleLL* new_node = new DoubleLL(data);
    if(head == NULL || pos == 0){
        head = new_node;
        return;
    }

    int count = 1;


    DoubleLL* temp = head;

    while(count != pos && count< pos){
        temp = temp -> next;
        count ++;
    }

    new_node -> next = temp;
    new_node -> prev = temp -> prev;
    temp -> prev = new_node;
    if (temp->prev != NULL )temp->prev->next = new_node;
}

int main(){
    DoubleLL* head = new DoubleLL(11);

    insert(head, 22, 1);
    insert(head, 33, 2);
    insert(head, 44, 3);
    insert(head, 55, 4);

    print(head);

    return 0;
}