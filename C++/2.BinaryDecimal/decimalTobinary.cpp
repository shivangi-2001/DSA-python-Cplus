#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter Decimal Number: ";
    cin >> n;

    string ans;

    while(n != 0){
        ans += (n&1)? '1': '0';
        n /= 2;
    }

    reverse(ans.begin(), ans.end());

    cout << "\nBinary Number: " << ans;
    return 0;
}