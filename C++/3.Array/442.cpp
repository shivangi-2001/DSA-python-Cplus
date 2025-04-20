    #include<iostream>
    #include<vector>
    using namespace std;
    #include <algorithm>

    vector<int> findDuplicates(vector<int>& nums) {
            vector<int> ans;
            sort(nums.begin(), nums.end());

            for(int i=0; i<nums.size(); i++){
                if(i+1<nums.size() && nums[i] == nums[i+1]){
                    ans.push_back(nums[i]);
                }
            }

            return ans;
    }


    int main(){
        vector<int> nums;

        nums.push_back(1);
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(2);
        nums.push_back(2);
        nums.push_back(4);

        vector<int> ans = findDuplicates(nums);

        for(auto it: ans){
            cout << it << endl;
        }
        return 0;
    }