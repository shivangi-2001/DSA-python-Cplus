#include <iostream>
using namespace std;

int reverse(int x) {
        int ans = 0;

        while(x!=0){
            int rem = x%10;
            if( ans > INT_MAX/10 ){
                return 0;
            }
            if( ans < INT_MIN/10 ){
                return 0;
            }
            ans = ans*10 + rem;
            x /= 10;
        }

        return ans;
}
int main() {
    
    cout << reverse(123) << endl;
    return 0;
}