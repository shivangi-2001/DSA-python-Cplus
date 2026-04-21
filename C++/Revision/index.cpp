#include<iostream>
#include<string>
#include<vector>
using namespace std;

int power(int a, int b){
    if(b==1) return a;
    int ans = 1;
    while(b!=0){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}
int main(){
    int a = 2;
    int b = 10;

    cout << power(a, b);
    return 0;
}