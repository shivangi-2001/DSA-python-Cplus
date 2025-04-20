#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    vector<int> res(nums.size(), 0);
    int odd = nums.size()-1;
    int even = 0;

    for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                res[even] = nums[i];
                even++;
            }else{
                res[odd]=nums[i];
                odd--;
            }
    }

    return 0;
}