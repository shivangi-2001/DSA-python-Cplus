#include<iostream>
using namespace std;

void passByValue(int *p){
    cout << "address Update p: " << p+1 << endl;
    cout << "value Update p: " << *p+1 << endl;
}

void passByReference(int (&p)[6]){
    cout << "value Update p: " << *p+1 << endl;
    cout << "address Update p: " << p+1 << endl;
    p[0] = p[0] + 1;
}

int main(){
    int arr[6];
    int c = 10;
    for(int i=0; i<6; i++){
        arr[i] = c*(i+1);
    }

    int *p = arr;


    for(int i=0; i<6; i++){
        cout << arr[i]  << " ";
    }
    cout<< endl;


    cout << "Address of arr: " << p << endl;
    cout << "Value at index of 0: "<< *p << endl;

    cout << "Value update at 0 index by pointer: " << *p+4 << endl;
    cout << "value update at index 3 by pointer: " << *(p+2) + 100 << endl;

    cout<< endl;

    // pass pointer
    passByValue(p);
    cout << "Address of p: "<< p << endl;
    cout << "value of p: "<< *p << endl;

    cout << endl;

    passByReference(arr);
    cout << "Address of p: "<< p << endl;
    cout << "value of p: "<< *p << endl;

    return 0;
}