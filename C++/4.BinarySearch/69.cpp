#include<iostream>
#include<vector>
using namespace std;

int sqrt(int x){
    int s = 0;
    int e = x;
    int ans = 0;
    if(x <= 1) return x;

    while (s<=e)
    {
        int mid = s+(e-s)/2;
        if(1LL * mid * mid <= x){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    
    return ans;
}

int main(){
    int x = 989634;

    // square root of x
    int ans = sqrt(x);
    cout <<  ans << endl;


    return 0;
}