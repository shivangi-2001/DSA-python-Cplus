#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums;
    nums.push_back(2536);
    nums.push_back(1613);
    nums.push_back(3366);
    nums.push_back(162);
    int n = nums.size();
    vector<int> maxDigit(n, -1);

    for(int i=0; i<n; i++){
        int num = nums[i];
        while(num > 0){
            maxDigit[i] = max(maxDigit[i], num % 10);
            num /= 10;
        }
    }

    int maxi = -1;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(maxDigit[i] == maxDigit[j]){
                int sum = nums[i] + nums[j];
                maxi = max(sum, maxi);
            }
        }
    }

    cout << maxi;

    return 0;
}