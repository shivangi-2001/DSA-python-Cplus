#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> num;
    num.push_back(0);
    num.push_back(0);
    num.push_back(1);
    num.push_back(1);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);

    int s = 0;
    int e = num.size()-1;

    while(s<=e){
        if(num[s] == 1 && num[e] == 0){
            swap(num[s], num[e]);
            s++;
        }else if(num[s] == 1 && num[e] == 1){
            e--;
        }
        else{
            s++;
        }
    }

    for(int i=0; i<num.size(); i++){
        cout << num[i] <<" ";
    }

    return 0;
}