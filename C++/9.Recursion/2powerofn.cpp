#include<iostream>
using namespace std;

int POWER(int base, int p){
    if(p == 0) return 1;
    if(p == 1) return base;

    int ans = 2*POWER(2, p-1);

    return ans;
}

int main(){
    int power;
    cin >> power;

    int ans = POWER(2, power);
    cout << ans;
    return 0;
}