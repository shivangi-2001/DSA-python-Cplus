#include<iostream>
#include<string>
using namespace std;

void letterCombination(string& digits, string& result, vector<string>& output, int idx){
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(idx >= digits.length()){
        output.push_back(result);
        return;
    }

    int ele = digits[idx]-'0';
    string word  = mapping[ele];

    for(int i=0; i<word.length(); i++){
        result+=word[i];
        letterCombination(digits, result, output, idx+1);
        result.pop_back();
    }

}

int main(){
    string digits = "732";
    vector<string> output = {};
    string result = "";

    if(digits.length() <= 0){
        return 0;
    }

    letterCombination(digits, result, output, 0);

    for(auto it: output){
        cout << it << " ";
    }

    return 0;

}