#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        for(size_t i=0; i<nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum < 0){
                sum = 0;
            }
        }

        return maxi;
}

int main(){
    vector<int> num;
    num.push_back(0);
    num.push_back(1);
    num.push_back(4);
    num.push_back(7);
    num.push_back(8);

    // int max_sum = num[0];
    // for (int i = 0; i < num.size(); i++) {
    //     int current_sum = 0;
    //     for (int j = i; j < num.size(); j++) {
    //         current_sum += num[j];
    //         max_sum = max(max_sum, current_sum);
    //         }
    // }
    // cout << "Maximum subarray sum using O(n^2) is " << max_sum << endl;

    int maxi = num[0];
    int sum = num[0];

    for(int i=0; i<num.size(); i++){
        maxi += num[i];
        sum = max(maxi, sum);
    }

    cout << sum << endl;

    return 0;
}


