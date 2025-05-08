#include<iostream>
using namespace std;

int SumOfArray(int arr[], int size){
    if(size <= 0) return 0;
    int ans = arr[0];
    cout << arr[0] << endl;
    ans += SumOfArray(arr+1, size-1);
    return ans;
}

int main(){
    int arr[5] = {3, 4, 1, 5, 1};
    int ans  = SumOfArray(arr, 5);

    cout << ans;
    return 0;
}