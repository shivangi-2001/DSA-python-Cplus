#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target, bool is_searching_left){
    int idx = -1;
    int start = 0;
    int end = nums.size()-1;
    while (start <= end)
    {
       int mid = start + (end - start)/2;
       if(nums[mid] > target){
        end =mid -1;
       }else if(nums[mid] < target){
        start = mid+1;
       }
       else{
        idx =mid;
        if(is_searching_left){
            end=mid-1;
        }else{
            start = mid+1;
        }
       }
    }

    return idx;
    
}

vector<int> searchRange(vector<int>& nums, int target) {
    int left = binarySearch(nums, target, true);
    int right = binarySearch(nums, target, false);

    return {left, right};
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}