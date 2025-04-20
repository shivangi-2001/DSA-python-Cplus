#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string largetNumber(vector<int> nums){
    vector<string> array;
    for(int i=0; i<nums.size(); i++){
        array.push_back(to_string(nums[i]));
    }
    
    sort(array.begin(), array.end(), [](const string &a, const string &b){
        return a+b > b+a;
    });

    string result = "";
    for(int i=0; i<array.size(); i++){
        result += array[i];
    }
    return result;
}


int main(){
    vector<int> nums = {3, 30, 34, 9, 5};

    string ans = largetNumber(nums);
    cout << ans;
    return 0;
}
