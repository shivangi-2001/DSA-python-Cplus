#include<iostream>
#include<string>
using namespace std;

bool stringRotate(string s, string goal){
    if(s.length() != goal.length()) return false;
    return (s+s).find(goal) != string::npos;
}

int main(){
    string s = "defdefdefabcabc";
    string goal = "defdefdefabcabc";

    bool ans = stringRotate(s, goal);
    cout << ans;
    return 0;
}