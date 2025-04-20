#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int ans = 1;
    for(int i=2; i<n; i++){
        if(n%i != 0){
            continue;
        }
        else{
            cout << "Not prime" << endl;
            ans=0;
            break;
        }
    }
    
    if(ans==1) cout << "Is prime" << endl;

    return 0;
}