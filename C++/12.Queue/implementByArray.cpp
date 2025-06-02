#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;

    public:

    Queue(int s){
        size = s;
        arr = new int[s];
        rear = 0;
        qfront = 0;
    }

    bool push(int d){
        if(rear == size){
            return 0;
        }
        if(rear<size){
            arr[rear++] = d;
        }

        return 1;
    }

    int pop(){
        if(qfront == rear){
            return -1;
        }else{
            int temp = arr[qfront];
            qfront++;
            if(rear == qfront){
                qfront = 0;
                rear = 0;
            }
            return temp;
        }
    }

    bool empty(){
        if(qfront == rear){
            return true;
        }
        return false;
    }

    int front(){
        if(qfront == rear){
            return -1;
        }
        return arr[qfront];
    }
};

int main(){
    Queue* q1 = new Queue(3);
    // cout << "Front: " << q1->top() << endl;
    cout << "push: "<< q1->push(10) << endl;
    cout << "pop: " << q1->pop() << endl;
    cout << "push: "<<  q1->push(20) << endl;
    cout << "Front: " << q1->front() << endl;
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