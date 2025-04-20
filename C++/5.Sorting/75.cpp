#include<iostream>
#include<vector>
using namespace std;

void sortColor(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        int min = i;
        for(int j=i+1; j<nums.size(); j++){
            if(nums[j]<nums[min]){
                min = j;
            }
        }
        swap(nums[i], nums[min]);
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};

    sortColor(nums);
    for(auto it: nums){
        cout << it << " ";
    }
    return 0;
}