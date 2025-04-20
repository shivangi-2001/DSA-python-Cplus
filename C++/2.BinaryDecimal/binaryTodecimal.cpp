#include<iostream>
#include<string>
using namespace std;

int main(){
    string n;
    cout << "Enter binary Number: ";
    cin >> n;

    int k=0;

    int sum = 0;

    for(int i=n.size()-1; i>=0; i--){
        if( n[i] == '0'){
            sum += 0*pow(2,k);
        }
        else{
            sum += 1*pow(2,k);
        }

        k++;
    }

    cout << "\nDecimal Number: " << sum;

    return 0;
}