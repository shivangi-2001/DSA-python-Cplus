#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) {
    int carry = 0;
    vector<int> ans;
    int n = num.size();
    int i = n-1;
    while(k != 0){
        int rem = k%10;
        int res = carry + num[i] + rem;
        carry = res/10;
        ans.push_back(res%10);
        k /= 10;
        i--;
    }

    while(carry != 0){
        ans.push_back(carry%10);
        carry /= 10;
    }

    while(i >= 0){
        ans.push_back(num[i]);
        i--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 1, 5};
    int k = 12;
    vector<int> ans = addToArrayForm(nums, k);
    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}