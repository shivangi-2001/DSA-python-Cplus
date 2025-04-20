#include<iostream>
using namespace std;

int main(){
    int a = 0;
    int b = 1;

    int n;
    cout << "Enter position: ";
    cin >> n;

    if(n>1){
        int total;
        for(int i=1; i<n; i++){
            total = a+b;
            a = b;
            b = total;
        }

        cout << "\nAt n position: "<< n << " value is n " << total;
    }else{
        cout << "\nAt n position: "<< n << " value is n "  << n;
    }
    return 0;
}