#include<iostream>
#include<vector>
using namespace std;

void subsets(vector<int> nums, int index, vector<int>& output, vector<vector<int>>& ans){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    subsets(nums, index+1, output, ans);

    int ele = nums[index];
    output.push_back(ele);

    subsets(nums, index+1, output, ans);

    output.pop_back();
}


int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;

    int index = 0;

    subsets(nums, index, output, ans);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}