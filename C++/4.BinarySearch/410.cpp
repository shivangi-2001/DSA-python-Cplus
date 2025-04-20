#include<iostream>
using namespace std;

bool isPossible(vector<int>& nums, int mid, int k){
    int m = 1;
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]+sum <= mid){
            sum += nums[i];
        }else{
            m++;
            if(m > k || nums[i] > mid){
                return false;
            }
            sum = nums[i];
        }
    }

    return true;
}
int splitArray(vector<int>& nums, int k) {
    int e = 0;
    for(int i=0; i<nums.size(); i++){
        e += nums[i];
    }

    int s = 0;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;
        if(isPossible(nums, mid, k)){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }

    return ans;
}
int main(){
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    // Assign maximum pages to a student is minized
    int ans = splitArray(nums, k);
    cout << ans << endl;

    return 0;
}