#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> grid){
    int top = 0;
    int bottom = grid.size()-1;

    int left = 0;
    int right = grid[0].size()-1;

    vector<int> ans;
    while((left <= right) && (top <= bottom)){
        for(int j=left; j<=right; j++){
            ans.push_back(grid[top][j]);
        }
        top++;

        for(int i=top; i<=bottom; i++){
            ans.push_back(grid[i][right]);
        }
        right--;

        if(top<=bottom){
            for(int j=right; j>=left; j--){
                ans.push_back(grid[bottom][j]);
            }
            bottom--;
        }

        if(left <= right){
            for(int i=bottom; i>= top; i--){
                ans.push_back(grid[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    vector<int> ans = spiralMatrix(grid);
    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}