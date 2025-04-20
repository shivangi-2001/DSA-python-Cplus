#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums.size()-i-1; j++){
            if(nums[j+1]<nums[j]){
                swap(nums[j+1], nums[j]);
            }
        }
    }
}

int main(){
    vector<int> nums = {64,25,12,22,11};
    bubbleSort(nums);
    for(auto it: nums){
        cout << it << " ";
    }
    return 0;
}