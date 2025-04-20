#include<iostream>
using namespace std;

int findDuplicate(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);

        int min = *min_element(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            ans[nums[i]-min]++;
        }

        for(int i=0; i<ans.size(); i++){
            if(ans[i] > 1){
                return i+min;
            }
        }

        return 0;
}
int main(){
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(4);

    int ans= findDuplicate(nums);

    cout << ans << endl;

    return 0;
}