#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            next = nullptr;
        }
};

class Stack{
    public: 
        Node* top;
    
        Stack(){
            this -> top = NULL;
        }

        void push(int data){
            Node* newnode = new Node(data);
            newnode -> next = top;
            top = newnode;
        }

        int peek(){
            if(top == NULL) return -1;
            return top -> data;
        }

        void pop(){
            if(top == NULL){
                cout << "Stack underflow" << endl;
                return;
            }
            Node* temp = top;
            top = top -> next;
            cout << "Deleting Top value: " << temp -> data << endl;
            delete temp;
        }

        bool empty(){
            return top == NULL;
        }
};

int main(){
    Stack s;
    s.push(3);
    s.push(5);
    cout << "peek element: " << s.peek() << endl;
    cout << "Add value: " << endl;
    s.push(190);
    cout << "Add value: " << endl;
    s.push(52);
    s.pop();
    s.pop();
    cout << "peek element: " << s.peek() << endl;
    s.pop();
    s.pop();
    cout << "stack empty: " << s.empty() << endl;
    s.pop();
    return 0;
}