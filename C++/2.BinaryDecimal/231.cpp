#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int count =0;
        
        while(n!=0){
            if(n&1){
                count++;
            }
            n >>= 1;
        }

        return count>1 ? false: true;
}

int main(){
    cout << isPowerOfTwo(9) << endl;
    return 0;
}