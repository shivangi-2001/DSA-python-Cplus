#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    unordered_map<int, int> mp;
    int count = 0;

    for(int i=0; i<nums.size(); i++){
        if (nums[i] == x)
        {
            mp[++count] = i;
        }
    }

    vector<int> ans(queries.size(), -1);

    for(int i=0; i<queries.size(); i++){
        if(mp.find(queries[i]) != mp.end()){
            ans[i] = mp[queries[i]];
        }else{
            ans[i] = -1;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {1,3,1,7};
    vector<int> queries = {1,3,2,4};
    int x = 1;

    vector<int> ans = occurrencesOfElement(nums, queries, x);

    for(auto it: ans){
        cout <<  it << " ";
    }


    return 0;
}