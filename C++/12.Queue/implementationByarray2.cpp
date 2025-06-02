#include<iostream>
using namespace std;

class Queue{
    public:
    int n;
    int *arr;
    int qfront;
    int rear;

    Queue(int n){
        this -> n = n;
        arr = new int[n];
        qfront = -1;
        rear = -1;
    }

    bool push(int d){
        if(qfront == -1 && rear == -1){
            qfront = rear = 0;
        }
        else if(rear == n-1){
            cout << "Overflow ";
            return 0;
        }else{
            rear++;
        }
        arr[rear]=d;
        cout << endl;
        for(int i=0; i<n; i++){
            cout << arr[i] <<" ";
        }
        cout << endl;
        return 1;
    }

    int pop(){
        if(qfront == -1){
            cout <<"Underflow: ";
            return -1;
        }
        int val = arr[qfront];
        arr[qfront]=0;
        qfront++;
        
        if(qfront == n){
            rear = -1;
            qfront = -1;
        }
        cout << endl;
        for(int i=0; i<n; i++){
            cout << arr[i] <<" ";
        }
        cout << endl;

        return val;
    }

    int front(){
        if(qfront == -1 && rear == -1){
            return -1;
        }
        return arr[qfront];
    }
};


int main(){
    Queue* q1 = new Queue(3);
    // cout << "Front: " << q1->top() << endl;
    cout << "push: "<< q1->push(-1) << endl;
    cout << "pop: " << q1->pop() << endl;
    cout << "push: "<<  q1->push(20) << endl;
    cout << "Front: " << q1->front() << endl;
    cout << "push: "<< q1->push(30) << endl;
    cout << "push: "<< q1->push(40) << endl;
    cout << "push: "<< q1->push(50) << endl;
    cout << "pop: " << q1->pop() << endl;
    cout << "pop: " << q1->pop() << endl;
    cout << "pop: " << q1->pop() << endl;
    cout << "push: "<< q1->push(-1) << endl;
    cout << "push: "<< q1->push(20) << endl;
    cout << "Front: " << q1->front() << endl;
    cout << "push: "<< q1->push(11) << endl;
    cout << "push: "<<  q1->push(1) << endl;
    cout << "Front: " << q1->front() << endl;
    cout << "pop: " << q1->pop() << endl;
    return 0;
}
