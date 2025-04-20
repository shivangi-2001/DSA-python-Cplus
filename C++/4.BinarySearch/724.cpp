#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int pivotIndex(vector<int>& nums) {
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
    }

    int ans = -1;
    // point indexing
    for(int i=0; i<nums.size(); i++){
        // count sum from left
        int left = 0;
        for(int j=0; j<i; j++){
            left += nums[j];
        }

        if(left == (sum - (nums[i]+left))){
            return i;
        }
    }

    return -1;
}

int main(){
    vector<int> nums = {2, 1, -1};

    int ans  = pivotIndex(nums);

    cout << ans << endl;
    return 0;
}