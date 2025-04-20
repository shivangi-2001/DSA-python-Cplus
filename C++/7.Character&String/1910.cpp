#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string removeOccurrences(string s, string part) {
    while(s.find(part) != string::npos){
        s.erase(s.find(part), part.length());
    }

    return s;
}

int main(){
    string s = "abbbacabca", part="abc";
    string ans = removeOccurrences(s, part);

    cout << ans;

    return 0;
}