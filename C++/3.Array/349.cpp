#include<iostream>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]>nums2[j]){
                j++;
            }else if(nums1[i] < nums2[j]){
                i++;
            }else if(nums1[i] == nums2[j]){
                if(ans.empty() || ans.back() != nums1[i])
                    ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return ans;
}
int main(){

    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(1);

    nums2.push_back(2);
    nums2.push_back(2);

    vector<int> ans = intersection(nums1, nums2);

    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}