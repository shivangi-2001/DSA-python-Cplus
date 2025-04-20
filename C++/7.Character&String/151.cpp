#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string reverseWords(string s) {
    vector<string> input;
    int start = 0;
    while(start < s.length()){
        if(isalnum(s[start])){
            int end = start;
            while(end < s.length() && s[end] != ' '){
                end++;
            }

            input.push_back(s.substr(start, end-start));
            start = end;
        }
        start++;
    }

    reverse(input.begin(), input.end());
    string output;  

    for(int i=0; i<input.size(); i++){
        if( i == input.size()-1){
            output += input[i];
        }
        else{
            output += input[i] + ' ';
        }
    }

    return output;
}

int main(){
    string s = " hello world ";
    // output "world hello";
    string ans = reverseWords(s);
    // Input: s = "a good   example"
    // Output: "example good a"

    cout<< ans;

    return 0;
}