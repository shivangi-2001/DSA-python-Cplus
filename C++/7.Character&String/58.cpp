#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int lengthOfLastWord(string s) {
    istringstream ss(s);
    string word;
    vector<string> input={};

    while(ss >> word){
        input.push_back(word);
    }

    string lastw = input[input.size()-1];

    return lastw.length();

    
}