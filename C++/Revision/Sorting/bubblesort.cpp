#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr, int size){
    if(size == 1) return;
    for(int i=0; i<size-1; i++){
        if (arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
    }
    bubbleSort(arr, size-1);
}

int main(){
    // Bubble sort (stable)
    vector<int> arr = {64, 12, 22, 32, 10, 8};

    bubbleSort(arr, arr.size());

    // for(int i=0; i<arr.size()-1; i++){
    //     for(int j=0; j<arr.size()-1; j++){
    //         if (arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
    //     }
    // }

    for(auto a: arr){
        cout << a << " ";
    }

    return 0;
}