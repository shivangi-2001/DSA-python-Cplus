#include<iostream>
#include<algorithm>
using namespace std;

int search(vector<int>& arr, int target){
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){
        int mid = start +(end-start)/2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] >= arr[start]){
            if((arr[start] <= target) && target < arr[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        else{
            if((arr[mid] < target) && target <= arr[end]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }

    }

    return -1;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int ans = search(arr, target);

    cout << ans;
    return 0;
}