#include<iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    int j = 0;
    for(int i=1; i<n; i++){
        if(nums[i] != nums[j]){
            j++;
            nums[j] = nums[i];
        }
    }
    return j+1;
}

// int removeDuplicates(vector<int>& nums) {
//     vector<int> distinct; // Separate vector to store distinct elements

//     for (int i = 0; i < nums.size(); i++) {
//         // Only add unique elements
//         if (find(distinct.begin(), distinct.end(), nums[i]) == distinct.end()) {
//             distinct.push_back(nums[i]);
//         }
//     }

//     // Copy distinct elements back to nums
//     for (int i = 0; i < distinct.size(); i++) {
//         nums[i] = distinct[i];
//     }

//     return distinct.size();
// }


int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int ans = removeDuplicates(nums);
    cout << ans << endl;
    for(int i=0; i<ans; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}