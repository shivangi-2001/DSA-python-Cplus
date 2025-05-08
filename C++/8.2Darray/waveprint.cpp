#include<iostream>
#include<vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> grid){
    vector<int> temp;
    for(int j=0; j<grid[0].size(); j++){
        if(j&1){
            // when col is odd -> bottom to top
            for(int i=grid.size()-1; i>=0; i--){
                temp.push_back(grid[i][j]);
            }
        }else{
            // when col is even - > top to bottom
            for(int i=0; i<grid.size(); i++){
                temp.push_back(grid[i][j]);
            }
        }
    }
    return temp;
}


int main(){
    vector<vector<int>> grid = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    vector<int> nums = wavePrint(grid);

    for(auto it: nums){
        cout << it << " ";
    }

    return 0;
}