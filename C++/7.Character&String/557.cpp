#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string reverseWords(string s) {
    istringstream ss(s);
    string word, result;

    
    while(ss >> word){
        string newword = word;
        reverse(newword.begin(), newword.end());
        result +=  newword + " ";
    }

    result.pop_back();
    return result;
}
int main(){
    string s = " Let's Chnage the LeetCode problem";
    string ans = reverseWords(s);
    cout << ans;
    return 0;
}