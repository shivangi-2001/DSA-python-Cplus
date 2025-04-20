#include<iostream>
#include<vector>
using namespace std;

vector<int> AddToVector(vector<int>& nums1, vector<int>& nums2){
    int carry = 0;
    vector<int> ans;
    int n = nums1.size();
    int m = nums2.size();
    int i = n-1;
    int j = m-1;
    while(i>=0 && j>=0){
        int res = carry + nums1[i] + nums2[j];
        carry = res/10;
        ans.push_back(res%10);
        i--;
        j--;
    }
    while(i >= 0){
        int res = carry + nums1[i];
        carry = res/10;
        ans.push_back(res%10);
        i--;
    }
    while(j >= 0){
        int res = carry + nums2[j];
        carry = res/10;
        ans.push_back(res%10);
        j--;
    }
    while(carry != 0){
        ans.push_back(carry%10);
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> nums1 = {3, 5, 9, 0, 0, 8};
    vector<int> nums2 = {1, 2, 3};
    vector<int> ans = AddToVector(nums1, nums2);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}