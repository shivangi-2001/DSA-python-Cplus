#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int row = 0;
    int col = matrix.size()-1;

    while(row < matrix.size() && col >= 0){
        int current = matrix[row][col];
        if(current == target){
            return true;
        }
        else if(current > target){
            col --;
        }else{
            row++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;

    bool ans = searchMatrix(matrix, target);
    cout << ans;
    return 0;
}