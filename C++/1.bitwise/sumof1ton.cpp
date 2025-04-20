#include<iostream>
using namespace std;


int main(){
    int n;
    cout << "Enter the n value: ";
    cin >> n;

    int total = n * (n + 1) / 2;

    cout << "\nSum of total: " << total << "\n";
    return 0;
}