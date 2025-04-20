#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    while(b != 0){
        int t = b;
        b = a % b;
        a = t;
    }
    cout << a << endl;
    return 0;
}