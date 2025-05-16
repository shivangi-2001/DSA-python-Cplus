#include<iostream>
using namespace std;

class Node {
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

void insertionAtTail(Node* &tail, int data){
    Node* new_node = new Node(data);
    tail -> next = new_node;
    tail = tail -> next;
}

void print(Node* & head){
    Node * temp = head;
    while(temp !=NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int length(Node* &head){
    int len = 0;
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp ->next;
    }
    
    return len;
}

void insertionAtMiddle(Node* &head, Node* &tail, int index, int data){
    if(index <= 0){
        cout << "Invalid index\n";
        return;
    }

    if(index == 1){
        insertionAtHead(head, data);
        if (tail == NULL) tail = head;
        return;
    }

    int len = length(head);
    if(index > len){
        insertionAtTail(tail, data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < index - 1){
        temp = temp -> next;
        count++;
    }

    Node* new_node = new Node(data);
    new_node -> next = temp -> next;
    temp -> next = new_node;

    if(new_node -> next == NULL){
        tail = new_node;
    }
}

void deleteAtIndex(Node* &head, Node* &tail, int index){
    if(index <= 0){
        cout << "Index out of bound" << endl;
        return;
    }

    if(index == 1){
        head = head -> next;
        return;
    }

    int len = length(head);
    if(index > len){
        cout << "Length is out of range " << len;
        return;
    }

    int count = 1;
    Node* prev = NULL;
    Node* temp = head;
    while(count < index){
        count++;
        prev = temp;
        temp = temp->next;
    }

    prev -> next = temp -> next;

    if(temp -> next == NULL){
        tail = prev;
        return;
    }

    delete temp;
}

Node* floydCycleDetection(Node*& Head, Node*& fast, Node*& slow){

    while(fast!=NULL && fast->next!=NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
        if( slow == fast ){
            return slow;
        }
    }

    return Head;
}

Node* startingNode(Node*& point, Node*& slow){
    while(point != slow){
        slow = slow -> next;
        point = point -> next;
    }
    return slow;
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;
    head = new Node(10);
    tail = head;

    // head insertion
    insertionAtHead(head, 5);
    insertionAtHead(head, 20);
    Node* ll = head;
    insertionAtHead(head, 40);
    insertionAtHead(head, 10);
    insertionAtHead(head, 12);
    print(head);

    tail -> next = ll;

    Node* fast = head;
    Node* slow = head;

    Node* point = floydCycleDetection(head, fast, slow);

    // slow equal to head
    slow = head;
    Node* startNode = startingNode(point, slow);

    cout << startNode -> data << endl;
    return 0;
}