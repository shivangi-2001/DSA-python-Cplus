#include<iostream>
#include<vector>

using namespace std;
int celebrity(vector<vector<int> >& mat) {
    // code here
    
    bool celebrity = true;
    int ans= -1;
    for(int i=0; i<mat.size(); i++){
        // check the celebrity in row [means o's in all row]
        for(int j=0; j<mat.size(); j++){
            if(i!=j && mat[i][j] == 1){
                celebrity=false;
            }
        }

        
        if(celebrity) {
            
            // check the potential candidate in row have all 1's in cols
            for(int j=0; j<mat.size(); j++){
                if(i!=j && mat[j][i]!=1){
                    celebrity=false;
                }
            }
        }
        
        if(celebrity) ans=i;
        
    }
    
    return ans;
}

int main(){
    vector<vector<int>> nums = {{1,1,1}, {0,1,0}, {1,0,1}};

    int ans = celebrity(nums);
    cout << ans;
    return 0;
}