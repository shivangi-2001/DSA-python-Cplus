#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(12);

    int last=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i], nums[last]);
            last++;
        }
    }

    for(auto it: nums){
        cout << it << " ";
    }
    return 0;
}