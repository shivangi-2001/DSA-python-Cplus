#include<iostream>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp(n, -1);
    for(int i=0; i<n; i++){
        temp[(i+k)%n] = nums[i];
    }

    for(int i=0; i<temp.size(); i++){
        nums[i]=temp[i];
    }

}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(nums, k);
    for(auto it: nums){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
