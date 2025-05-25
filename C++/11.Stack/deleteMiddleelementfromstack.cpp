#include<iostream>
#include<stack>
using namespace std;

void deleteMiddle(stack<int>&inputStack, int N){
    // Write your code here
    int mid = 0;
    stack<int> ans;
    if(N%2 != 0){
        // even
        mid = (N+1)/2 - 1;
        int count = 0;
        while(!inputStack.empty()){
            if(count != mid){
                // cout << inputStack.top() << endl;
                ans.push(inputStack.top());
            }
            count++;
            inputStack.pop();
        }

    }else{
        // odd
        mid = (N+1)/2;
        int count = 0;
        while(!inputStack.empty()){
            if(count != mid){
                ans.push(inputStack.top());
            }
            count++;
            inputStack.pop();
        }
    }

    while (!ans.empty())
    {
        inputStack.push(ans.top());
        ans.pop();
    }
    
    
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    int n = 3;

    deleteMiddle(s, n);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}