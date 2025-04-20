#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        int s =0;
        int e= nums.size()-1;

        while(s<=e){
            if(nums[s] == val && nums[e] == val){
                e--;
            }else if(nums[s] != val && nums[e] == val){
                e--;
                s++;
            }else if(nums[s] != val && nums[e] != val){
                s++;
            }else if(nums[s] == val && nums[e] != val){
                swap(nums[s], nums[e]);
                s++;
                e--;
            }
        }

        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                nums[i] = -1;
            }
            else{
                count++;
            }
        }

        return count;
}

int removeElement(vector<int>& nums, int val) {
    int s = 0;

    for(int i=0; i < nums.size(); i++){
        if(nums[i] != val){
            nums[s] = nums[i];
            s+=1;
        }
    }

    return s;
}

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(12);

    int val = 2;

    cout << removeElement(nums, val) << endl;

    return 0;
}