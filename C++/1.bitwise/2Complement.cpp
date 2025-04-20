#include<iostream>
#include<string>
using namespace std;


char flip(char c){
    return (c == '0')? '1': '0';
}

int main(){
    // int num;
    // cout << "Enter an integer: ";
    // cin >> num;

    // int twosComplement = ~num + 1;

    // cout << "2's complement of " << num << " is " << twosComplement << endl;

    string num;
    cout << "Enter an integer in binary: ";
    cin>> num;

    string ones;

    for (int i=0; i<num.length(); i++){
        ones += flip(num[i]);
    }

    cout << "1's Complements is: "  << ones;


    string twos;

    int carry = 1;
    for (int i = ones.length() - 1; i >= 0; i--) {
        if (ones[i] == '1' && carry == 1) {
            twos += '0';
        } else if (ones[i] == '0' && carry == 1) {
            twos += '1';
            carry = 0;
        } else {
            twos = twos + ones[i];
        }
    }

    reverse(twos.begin(), twos.end());

    cout << "\n2's Complement is: " << twos << endl;
    return 0;
}