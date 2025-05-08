#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    // column
    int top=0;
    int bottom=n-1;

    // row
    int left=0;
    int right=n-1;

    vector<int> input;
    for(int i=1; i<=n*n; i++){
        input.push_back(i);
    }

    int idx=0;

    vector<vector<int>> ans(n, vector<int>(n));

    while((left <= right) && (top <= bottom)){
        for(int j=left; j<=right; j++){
            ans[top][j] = input[idx++];
        }
        top++;

        for(int i=top; i<=bottom; i++){
            ans[i][right] = input[idx++];
        }
        right--;

        if(top <= bottom){
            for(int j=right; j>=left; j--){
                ans[bottom][j]=input[idx++];
            }
            bottom--;
        }

        if(left <= right){
            for(int i=bottom; i>=top; i--){
                ans[i][left]= input[idx++];
            }
            left++;
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> ans = generateMatrix(3);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout <<  endl;
    }
    return 0;
}