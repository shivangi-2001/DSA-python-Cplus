#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size()-1;

    int ans = -1;
    
    while(s <= e){
        int mid = s + (e-s)/2;
        if(nums[mid] == target){
            ans = mid;
            break;
        }
        else if(nums[mid] < target){
            s = mid+1;
        }else{
            e = mid-1;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 5;

    int ans = search(nums, target);

    cout << "Found at " << ans << endl;
    return 0;
}