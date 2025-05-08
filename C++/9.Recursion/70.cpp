#include<iostream>
using namespace std;

int climbStair(int n){
    if(n<=3) return n;

    int prev1 = 2;
    int prev2 = 3;
    int curr;

    for(int i=3; i<n; i++){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return curr;
}

int main(){
    int ans = climbStair(45);
    cout << ans;
    return 0;
}