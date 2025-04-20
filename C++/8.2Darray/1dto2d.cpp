#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> convert2Darray(vector<int>& nums, int m, int n){
    
}

int main(){

    vector<int> nums = {1,2,3,4};
    int n=2; //columns
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