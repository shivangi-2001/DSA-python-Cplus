#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    // insertion sort (stable)
    vector<int> arr = {64, 12, 22, 32, 10, 8};

    for(int i=1; i<arr.size(); i++){
        int key = arr[i];

        int j= i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }

    for(int a: arr){
        cout << a << " ";
    }

    return 0;
}