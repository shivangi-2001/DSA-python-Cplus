#include<iostream>
using namespace std;

int power(int a, int b){
    if(b == 0 ) return 1;
    if(a ==0) return 0;
    if(b == 1) return a;

    int ans = 1;
    while(b != 0){
        if(b&1){
            ans = a * ans;
        }
        a = a * a;
        b >>= 1;
    }

    return ans;
}

int main(){
    int a, b;
    cin >> a >> b;

    // power of a, b using O(log N)
    int ans = power(a,b);
    cout << ans << endl;
    return 0;
}