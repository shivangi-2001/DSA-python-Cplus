#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    string s1 = "a man is busy with study";

    int s = 0;

    while(s < s1.length()){
        if(s1[s] == ' '){
            s1.replace(s, 1, "@40");
        }
        s++;
    }

    cout << s1;
    return 0;
}