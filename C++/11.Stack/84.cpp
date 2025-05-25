#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElements(vector<int>& arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n,-1);
    for(int i=n-1; i>=0; i--){
        while(st.top()!=- 1 && arr[st.top()] >= arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallerElements(vector<int>& arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n,-1);
    for(int i=0; i<n; i++){
        while(st.top()!=-1 && arr[st.top()] >= arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> next = nextSmallerElements(heights, n);
    cout << "next: ";
    for(auto i: next){
        cout << i << " "; 
    }
    cout << endl;

    vector<int> prev = prevSmallerElements(heights, n);
    cout << "prev: ";
    for(auto i: prev){
        cout << i << " "; 
    }
    cout << endl;
    int area = INT_MIN;

    for(int i=0; i<n; i++){
        int l = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int w = next[i]-prev[i]-1;
        int newArea = l*w;
        area = max(area, newArea);
    }
        
    return area;
}
int main(){
    vector<int> heights = {2,1,5,6,2,3};
    int ans = largestRectangleArea(heights);
    cout << ans << endl;
    return 0;
}