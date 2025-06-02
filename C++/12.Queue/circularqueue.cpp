#include<iostream>
using namespace std;

class Queue{
    public:
        int *arr;
        int s;
        int front;
        int rear;

        Queue(int s){
            this -> s = s;
            front = -1;
            rear = -1;
            arr = new int[s];
        }

        bool push(int d){
            if((front == 0 && rear == s) || (rear == (front-1)%(s-1))){
                cout << "Overflow ";
                return 0;
            }
            if(front == -1 && rear == -1){
                front = rear = 0;
            }else if(front!=0 && rear == s-1){
                rear=0;
            }else{
                rear++;
            }
            arr[rear] = d;
            return 1;
        }

        int pop(){
            if(front == -1 && rear == -1){
                return -1;
            }
            int val = arr[front];
            if(front == s-1){
                front = 0;
            }else if(front == rear){
                rear = front = -1;
            }else{
                front++;
            }
            return val;
        }

        int top(){
            if(front == -1 && rear == -1){
                return -1;
            }
            return arr[front];
        }
};

int main(){
    int arr[10];
    arr[8]=10;
    cout << arr[-1] << endl;
    Queue* q1 = new Queue(3);
    // cout << "Front: " << q1->top() << endl;
    cout << "push: "<< q1->push(10) << endl;
    cout << "pop: " << q1->pop() << endl;
    cout << "push: "<<  q1->push(20) << endl;
    cout << "Front: " << q1->top() << endl;
    cout << "push: "<< q1->push(30) << endl;
    cout << "push: "<< q1->push(40) << endl;
    cout << "push: "<< q1->push(50) << endl;
    cout << "pop: " << q1->pop() << endl;
    cout << "pop: " << q1->pop() << endl;
    cout << "pop: " << q1->pop() << endl;
    cout << "push: "<< q1->push(40) << endl;
    cout << "push: "<< q1->push(20) << endl;
    cout << "push: "<< q1->push(11) << endl;
    cout << "push: "<<  q1->push(1) << endl;
    return 0;
}