#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int *arr;
        int top;

        Stack(int size){
            this -> size = size;
            this -> arr = new int[size]; // arr = new int[size];
            this -> top = -1; // top = -1;
        }

        void push(int data){
            if(top < size - 1){
                arr[++top]=data;
                cout << "Top " << top << endl;
                return;
            }else{
                cout << "Stack Overflow" << endl;
                return;
            }
        }

        int pop(){
            if(top < 0){
                cout << "Stack underflow" << endl;
                return 0;
            }
            return arr[top--];
        }

        int peek(){
            if(top < 0){
                cout << "Stack is Empty" << endl;
                return -1;
            }
            return arr[top];
        }

        bool empty(){
            return top<0;
        }
};

int main(){
    Stack s(5);

    s.push(1);
    s.push(2);
    cout << "pop element: " << s.pop() << endl;
    s.push(3);

    s.push(4);
    s.push(5);
    cout << "pop element: " << s.pop() << endl;
    s.push(6);

    cout << "peek element: " << s.peek()<< endl;

    return 0;
}