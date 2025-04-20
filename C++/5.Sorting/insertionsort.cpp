#include<iostream>
using namespace std;

void insertionsort(vector<int>& nums){
    for(int i=1; i<nums.size(); i++){
        int key = nums[i]; 
        int j = i-1;
        while(j>=0 && nums[j]>key){
            nums[j+1] = nums[j];
            j-=1;
        }
        nums[j+1] = key;
    }    
}

int main(){
    vector<int> nums = {64,25,12,22,11};
    insertionsort(nums);
    for(auto it: nums){
        cout << it << " ";
    }
    return 0;
}