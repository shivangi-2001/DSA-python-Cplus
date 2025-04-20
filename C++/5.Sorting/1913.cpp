#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProductDifference(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n-1]*nums[n-2] - nums[0]*nums[1];
}

int main(){
    vector<int> nums = {5,6,2,7,4};
    int ans = maxProductDifference(nums);
    cout << ans;
    return 0;
}