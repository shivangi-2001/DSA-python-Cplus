#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n-1;

    while(l <= r){
        int mid = l + (r-l)/2;
        if(nums[mid] == target) return true;

        if(nums[l] < nums[mid]){
            if(nums[l] <= target && target < nums[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }else if(nums[l] > nums[mid]){
            if(nums[mid] < target && target <= nums[r]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }else{
            l++;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {1,0,1,1,1};
    int target = 0;

    bool ans = search(nums, target);
    cout << ans << endl;

    return 0;
}