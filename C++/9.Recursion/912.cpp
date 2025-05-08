#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void shell(vector<int> &a, int n){
            for(int gap=n/2; gap>0; gap/=2){
                for(int i=gap; i<n; i++){
                    int temp = a[i];
                    int j=i;
                    while(j>=gap && a[j-gap] > temp){
                        a[j]=a[j-gap];
                        j-=gap;
                    }
                    a[j]=temp;
                }
            }
        }
    
        vector<int> sortArray(vector<int>& nums) {
            shell(nums, nums.size());
            return nums;
        }
};