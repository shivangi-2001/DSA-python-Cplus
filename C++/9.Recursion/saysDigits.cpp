#include<iostream>
#include<vector>
#include<string>
using namespace std;


void SayDigit(int n){
    vector<string> digits = {"One", "Two", "three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    if(n == 0) return;

    int rem = n%10;
    SayDigit(n/10);
    cout << digits[rem-1];
}

int main(){
    SayDigit(412);
    return 0;
}