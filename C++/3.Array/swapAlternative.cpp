#include<iostream>
#include<array>
using namespace std;

int main(){
    int arr[8] = {2,4,5,12,89,9,29,10};

    int s = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    int e = n - 1;
    for(int i=s; i<e-1; i+=2){
        int j = i+1;
        swap(arr[i], arr[j]);
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}