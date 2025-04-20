// Input: s = "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
// Example 2:

// Input: s = "azxxzy"
// Output: "ay"

#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

string removeDuplicates(string s) {
    vector<char> ss = {};
    for(int i=0; i<s.length(); i++){
        if(!ss.empty() && ss.back() == s[i]){
            ss.pop_back();
        }
        else{
            ss.push_back(s[i]);
        }
    }

    string result;
    for(auto it: ss){
        result+=it;
    }

    return result;
}

int main(){
    string s = "abbacaa";
    string ans = removeDuplicates(s);
    cout << ans;
    return 0;
}