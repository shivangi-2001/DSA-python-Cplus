#include<iostream>
#include<vector>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> v;

        for (int i = 0; i < arr.size(); i++) {
            int cnt = 1;
            while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                cnt++;
                i++;
            }
            v.push_back(cnt);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1]) {
                return false;
            }
        }
        return true;
}


int main(){
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(4);

    cout << uniqueOccurrences(nums) << endl;
    return 0;
}