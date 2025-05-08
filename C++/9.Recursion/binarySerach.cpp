#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(int arr[], int start, int end, int key){
    if(start>end){
        return -1;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] == key){
        return mid;
    }

    else{
        int index;
        if(arr[mid] > key){
            index = BinarySearch(arr, start, mid-1, key);
        }else{
            index = BinarySearch(arr, mid+1, end, key);
        }

        return index;
    }

}

int main(){
    int arr[] = {3, 10, 17, 19, 33, 37, 89, 100};
    int key = 3;
    int size = sizeof(arr)/sizeof(arr[0]);

    int start =0;
    int end = size-1;

    int ans = BinarySearch(arr, start, end, key);

    cout << ans;

    return 0;
}