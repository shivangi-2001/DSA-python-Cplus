#include<iostream>
using namespace std;

int subtractProductAndSum(int n) {
        int temp = n;
        int prod = 1;
        int sum = 0;
        while(temp != 0){
            int rem = temp % 10;
            prod *= rem;
            sum += rem;
            temp = temp/10;
        }
        return prod-sum;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans = subtractProductAndSum(n);

    cout << "result: " << ans <<endl; 
    return 0;
}