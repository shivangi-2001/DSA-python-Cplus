#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){ 
    int n;
    cout << "Enter range from 2 to: ";
    cin >> n;

    if(n<=2){
        cout << "number should be greater than 2"<< endl;
    }

    vector<int> nums;
    nums.push_back(2);

    for (int i=3; i <= n; i++){
        bool isPrime = true;
        for(int k=2; k <= sqrt(i); k++){
            if(i % k == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            nums.push_back(i);
        }
    }

    print(nums);
    return 0;
}