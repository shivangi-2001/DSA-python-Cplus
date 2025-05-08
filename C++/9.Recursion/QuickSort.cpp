#include<iostream>
using namespace std;

int partition(int* arr, int s, int e){
    // select the pivot element
    int p = s;

    // find the correct place for the pivot elment
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] < arr[p]){
            count++;
        }
    }

    int pivotIndex= count+s;
    // place the pivot element on that place
    swap(arr[s], arr[pivotIndex]);

    // move elmenet that greater than pivot element in right 
    // move element that less than pivot element in left
    int i=s;
    int j=e;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] <= arr[pivotIndex]){
            i++;
        }
        while(arr[j] > arr[pivotIndex]){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i], arr[j]);
        }
    }


    return pivotIndex;
}

void QuickSort(int* arr, int s, int e){
    // base condition
    if(s>=e){
        return;
    }
    // partition the array
    int pivotIndex = partition(arr, s, e);

    QuickSort(arr,s, pivotIndex-1);
    QuickSort(arr, pivotIndex+1, e);
}

int main(){
    int arr[] = {2, 4, 1, 7, 10};
    int n = 5;

    QuickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}