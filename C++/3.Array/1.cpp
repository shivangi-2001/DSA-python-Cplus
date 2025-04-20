#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {}; 
// }

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Stores value -> index mapping
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if the complement exists in the map
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; 
        }

        numMap[nums[i]] = i; // Store the index of the current number
    }
    return {}; // Return empty if no solution is found
}

int main(){
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(18);
    nums.push_back(2);
    nums.push_back(9);

    int target = 10; // Example target value
    vector<int> ans = twoSum(nums, target);

    for(auto it: ans){
        cout <<  it << endl;
    }

    return 0;
}