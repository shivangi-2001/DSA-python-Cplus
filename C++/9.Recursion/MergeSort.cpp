#include<iostream>
using namespace std;

void merge(int* arr, int left, int right){
    int mid = left + (right-left)/2;
    int n1 = mid-left+1;
    int n2 = right-mid;

    int *first = new int[n1];
    int *second = new int[n2];

    int index = left;
    for(int i=0; i<n1; i++){
        first[i] = arr[index++];
    }

    index = mid+1;
    for(int i=0; i<n2; i++){
        second[i] = arr[index++];
    }

    int i=0, j=0, k=left;

    while(i<n1 && j<n2){
        if(first[i] < second[j]){
            arr[k++] = first[i++];
        }else{
            arr[k++] = second[j++];
        }
    }

    while(i<n1){
        arr[k++] = first[i++];
    }

    while(j<n2){
        arr[k++] = second[j++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e){
    if(s >= e){
        return;
    }

    int mid = s+(e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
}

int main(){
    int arr[] = {-2,3,-5};
    int size = 3;

    mergeSort(arr, 0, size-1);

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
