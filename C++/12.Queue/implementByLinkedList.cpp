#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

class Queue{
    public:
    Node* qfront;
    Node* rear;
    Queue(){
        qfront=NULL;
        rear = NULL;
    }

    bool empty(){
        if(qfront == NULL && rear == NULL){
            return 1;
        }
        return 0;
    }

    void push(int d){
        Node* newnode = new Node(d);
        if(rear == NULL){
            rear = newnode;
            qfront = newnode;
            return;
        }
        rear -> next = newnode;
        rear = newnode;
    }

    int pop(){
        if(qfront == NULL){
            return -1;
        }
        int temp = qfront -> data;
        qfront = qfront -> next;

        return temp;
    }

    int front(){
        if(qfront == NULL){
            return -1;
        }
        return qfront -> data;
    }
};

int main(){
    Queue* q1 = new Queue();
    cout << "pop: " << q1->pop() << endl;
    cout << "Empty: " << q1->empty() << endl;
    q1->push(32);
    cout << "Empty: " << q1->empty() << endl;
    cout << "front: " << q1->front() << endl;
    q1->push(2);
    q1->push(34);
    cout << "front: " << q1->pop() << endl;
    q1->push(12);
    cout << "pop: " << q1->pop() << endl;
    q1->push(10);
    cout << "front: " << q1->front() << endl;
    cout << "pop: " << q1->pop() << endl;
    return 0;
}