#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {3, 9, 19, 1, -3, 7, 9};

    auto it = find(nums.begin(), nums.end(), 10);

    auto ite =  nums.end();

    auto itb  =  nums.begin();

    cout << "begin elemenet is: " << *itb << endl;
    cout << "End elemenet is: " << *ite << endl;


    if (it != nums.end()) {
        cout << "Element found at index: " << distance(nums.begin(), it) << endl;
    } else {
        cout << "Element not found  " << *it << endl;
    }

    return 0;
}
