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

Node* getMiddle(Node* head){
    // returns the node before the middle
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return prev; // node before middle
}

Node* merge(Node* left, Node* right){
    if(left == NULL) return right;
    if(right == NULL) return left;

    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while(left && right){
        if(left->data < right->data){
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if(left) temp->next = left;
    if(right) temp->next = right;

    Node* result = dummy->next;
    delete dummy;
    return result;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* midPrev = getMiddle(head);
    Node* mid = midPrev->next;
    midPrev->next = NULL; // break the list

    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    return merge(left, right);
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

    Node* ans = mergeSort(head);

    cout << "Sorted List: ";
    print(ans);

    return 0;
}
