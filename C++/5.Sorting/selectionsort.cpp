#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        int min =i;
        for(int j=i+1; j<nums.size(); j++){
            if(nums[min]>nums[j]){
                min = j;
            }
        }
        swap(nums[i], nums[min]);
    }
}

int main(){
    vector<int> nums = {64,25,12,22,11};
    selectionSort(nums);

    for(auto it: nums){
        cout << it << " ";
    }
    return 0;
}