#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> nums = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // rows
    int n = nums.size();
    // columns
    int m = nums[0].size();

    // print 2d array
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << nums[i][j] << " ";
        }
    }
    return 0;
}