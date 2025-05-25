#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    stack<char> s;
    // cout << (s.top() == -1 )<< endl;

    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');

    string ans;
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }

    cout << ans;


    return 0;
}