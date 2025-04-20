#include<iostream>
#include<vector>
using namespace std;

int factorial(int n){
    int ans = 1;
    if(n == 0 || n == 1) return 1;
    ans = n*factorial(n-1);

    return ans;
}

int main(){

    int n;
    cout << "Enter a number: " ;
    cin >> n;


    int ans = factorial(n);

    cout << ans ;

    return 0;
}