#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int d){
        this -> data = d;
        this -> next = nullptr;
    }
};

void insertAttail(Node*& tail, int d){
    Node* newnode = new Node(d);
    tail -> next = newnode;
    tail = newnode;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* solve(Node* list1, Node* list2){
    Node* temp1 = list1;
    Node* temp2 = list2;

    while(temp1 && temp2){
        if(temp1 -> next && temp1 -> data <= temp2 -> data && temp1 -> next -> data >= temp2 -> data){
            Node* forward1 = temp1 -> next;
            Node* forward2 = temp2 -> next;

            temp1 -> next = temp2;
            temp2 -> next = forward1;
            temp2 = forward2;
        }else{
            if(temp1 -> next){
                temp1 = temp1 -> next;
            }else{
                break;
            }
        }
    }

    if(temp2){
        while(temp1 -> next){
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp2;
    }

    return list1;
}

Node* mergeSortedLinkedList(Node* list1, Node* list2){
    // if(list1 == NULL){
    //     return list2;
    // }
    // if(list2 == NULL){
    //     return list1;
    // }

    // if(list1 -> data <= list2 -> data){
    //     return solve(list1, list2);
    // }else{
    //     return solve(list2, list1);
    // }

    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (list1 && list2)
    {
        if(list1 -> data <= list2 -> data){
            tail -> next = list1;
            list1 = list1 -> next;
        }else{
            tail -> next = list2;
            list2 = list2 -> next;
        }
        tail = tail -> next;
    }
    
    return dummy -> next;

}

int main(){
    Node* head1 = new Node(10);
    Node* tail1 = head1;
    insertAttail(tail1, 30);
    insertAttail(tail1, 60);
    insertAttail(tail1, 80);
    print(head1);

    Node* head2 = new Node(20);
    Node* tail2 = head2;
    insertAttail(tail2, 40);
    insertAttail(tail2, 50);
    insertAttail(tail2, 70);
    print(head2);


    Node* ans = mergeSortedLinkedList(head1, head2);

    print(ans);
    return 0;
}