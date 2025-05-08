#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>& m, vector<vector<int>>& visited, int n, int x, int y){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1){
        return true;
    }
    return false;
}

void solve(vector<vector<int>>& m, int n, vector<vector<int>>& visited, int x, int y, string path, vector<string>& ans){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down (D)
    int newx = x+1;
    int newy = y;
    if(isSafe(m, visited, n, newx, newy)){
        path.push_back('D');
        solve(m, n, visited, newx, newy, path, ans);
        path.pop_back(); // backtrack
    }

    // Left (L)
    newx = x;
    newy = y-1;
    if(isSafe(m, visited, n, newx, newy)){
        path.push_back('L');
        solve(m, n, visited, newx, newy, path, ans);
        path.pop_back();
    }

    // Up (U)
    newx = x-1;
    newy = y;
    if(isSafe(m, visited, n, newx, newy)){
        path.push_back('U');
        solve(m, n, visited, newx, newy, path, ans);
        path.pop_back();
    }

    // Right (R)
    newx = x;
    newy = y+1;
    if(isSafe(m, visited, n, newx, newy)){
        path.push_back('R');
        solve(m, n, visited, newx, newy, path, ans);
        path.pop_back();
    }

    visited[x][y] = 0; // backtrack
}

vector<string> RatInMaze(vector<vector<int>> m, int n){
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> ans;
    string path = "";

    if(m[0][0] == 0) return ans; // If starting point is blocked, no paths exist

    solve(m, n, visited, 0, 0, path, ans);
    return ans;
}

int main(){
    vector<vector<int>> m = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector<string> ans = RatInMaze(m, 4);

    for(auto it: ans){
        cout << it << endl;
    }
    return 0;
}
