#include<iostream>
using namespace std;

int power(int a, int b){
    if(b == 1) return a;
    if(b == 0) return 1;

    int ans = power(a, b/2);
    if(b%2 == 0) return a*a;
    else
        return ans * ans * a;
}

int main(){
    int ans =power(2,5);
    cout << ans;
    return 0;
}