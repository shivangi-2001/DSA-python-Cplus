#include<iostream>
using namespace std;

bool check(vector<int>& nums) {
    int count = 0;
    for(int i = 1; i<nums.size(); i++){
        if(i == nums.size()-1){
            if(nums[i]>nums[0]){
                count++;
            }
        }
        if(nums[i-1] > nums[i]){
            count++;
        }
    }
    return count > 1 ? false : true;
}

int main(){
    vector<int> nums = {2, 1, 3, 4};
    bool ans = check(nums);
    cout << ans << endl;
    return 0;
}