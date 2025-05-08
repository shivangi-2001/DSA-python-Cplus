#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> shift2D(vector<vector<int>> grid, int K){
    // column
    int n = grid[0].size();
    // rows
    int m = grid.size();

    
    vector<vector<int>> ans(m, vector<int>(n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int newVal = ((i*n+j)+K)%(m*n);
            ans[newVal%n][newVal/n] = grid[i][j];
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> grid = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    int k=4;

    vector<vector<int>> ans = shift2D(grid, k);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}