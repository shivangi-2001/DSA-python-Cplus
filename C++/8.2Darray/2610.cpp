#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>>ans;
    unordered_map<int,int>mp;
    int maxi=0;

    for(auto i:nums){
        mp[i]++;
    }
    for(auto i:mp){
        maxi=max(maxi,i.second);
    }

    for(int j=0;j<maxi;j++){
        vector<int>temp;
// referencing the count map by &
        for(auto& i:mp){
            if(i.second>0) {
                temp.push_back(i.first);
                i.second--;
            }
        }
        ans.push_back(temp);
    }
    return ans;
    
}
int main(){
    vector<int> nums = {1,3,4,1,2,3,1};
    vector<vector<int>> ans = findMatrix(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}