#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(4);

    // Search for an element 6
    int *out = nullptr;
    auto it = find(nums.begin(), nums.end(), 8);

    cout << nums.back() << endl;

//     it = find (myvector.begin(), myvector.end(), 30);
//   if (it != myvector.end())
//     std::cout << "Element found in myvector: " << *it << '\n';
//   else
//     std::cout << "Element not found in myvector\n";


    return 0;
}
