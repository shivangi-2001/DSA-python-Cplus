#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> convert2Darray(vector<int>& nums, int m, int n){
    if(m*n != nums.size()){
        return {};
    }

    int idx =0;
    vector<vector<int>> res(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            res[i][j] = nums[idx++];
        }
    }

    return res;
}

int main(){

    vector<int> nums = {1,2,3,4,7,9};
    int n=3; //columns
    int m=2; //rows

    vector<vector<int>> ans = convert2Darray(nums, m,n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}