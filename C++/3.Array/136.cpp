#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans ^= nums[i];
        }

        return ans;
}

int main(){
    vector<int> nums;

    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);

    cout << singleNumber(nums) << endl;
    return 0;
}