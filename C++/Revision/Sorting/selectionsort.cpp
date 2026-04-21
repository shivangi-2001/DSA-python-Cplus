#include<iostream>
#include<vector>
using namespace std;

int main(){
    // selection sort (unstable)
    vector<int> arr = {64, 12, 22, 32, 10, 8};

    for(int i=0; i<arr.size()-2; i++){
        int minIndx = i;
        for(int j=i+1; j<arr.size(); j++){
            if(arr[minIndx]>arr[j]){
                minIndx=j;
            }
        }
        swap(arr[minIndx], arr[i]);
    }

    for(auto a: arr){
        cout << a << " "; 
    }

    return 0;
}