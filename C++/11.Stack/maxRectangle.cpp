#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallestElement(vector<int> &arr, int n){
    vector<int> next(n, -1);
    
    stack<int> s;
    s.push(-1);
    for(int i=n-1; i>=0; i--){
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        next[i]=s.top();
        s.push(i);
    }
    
    return next;
}
vector<int> prevSmallestElement(vector<int> &arr, int n){
    vector<int> prev(n, -1);
    
    stack<int> s;
    s.push(-1);
    for(int i=0; i<n; i++){
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        prev[i]=s.top();
        s.push(i);
    }
    
    return prev;
}
int largestHistorgramArea(vector<int> &arr, int n){
    vector<int> next;
    vector<int> prev;
    
    next = nextSmallestElement(arr, n);
    prev = prevSmallestElement(arr, n);
    
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        int height = arr[i];
        if(next[i] == -1) next[i]=n;
        int width = next[i]-prev[i]-1;
        maxi = max(maxi, height*width);
    }
    
    return maxi;
}
int maxArea(vector<vector<int>> &mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    int maxi = INT_MIN;
    vector<int> heights(m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            heights[j] = (mat[i][j] == 0) ? 0 : heights[j] + 1;
        }
        int area = largestHistorgramArea(heights, m);
        maxi = max(maxi, area);
    }
    
    return maxi;
}

int main(){
    vector<vector<int>> mat = {{0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}};

    int ans = maxArea(mat);
    cout << ans;
    return 0;
}