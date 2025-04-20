#include<iostream>
#include<vector>
using namespace std;


void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1; // Last element of nums1
    int j = n - 1; // Last element of nums2
    int k = m + n - 1; // Last position of merged array

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int>num2 = {2,5,6};
    int n = 3;

    mergeSortedArray(nums1, m, num2, n);
    for(auto it: nums1){
        cout << it << " ";
    }
    return 0;
}