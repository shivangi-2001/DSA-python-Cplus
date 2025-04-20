#include<iostream>
using namespace std;

int hammingWeight(int n) {
        int count = 0;
        while(n != 0){
            if (n&1){
                count++;
            }
            n >>= 1;
        }

        return count;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans = hammingWeight(n);

    cout << "result: " << ans <<endl; 
    return 0;
}