#include<iostream>
using namespace std;

bool isPalindrome(int x) {
        if(x<0) return false;

        int temp = x;
        int ans = 0;
        while(temp != 0){
            int rem = temp % 10;
            if( ans < INT_MIN/10 || ans > INT_MAX/10) return 0;
            ans = ans*10 + rem;
            temp /= 10;
        }

        return ans == x;
}

int main(){
    cout << isPalindrome(-129) << endl;
    return 0;
}