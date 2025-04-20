#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void reverseWords(vector<char>& s){
    reverse(s.begin(), s.end());
    int start = 0;
    
    while(start < s.size()){
        int end = start;
        while(end < s.size() && s[end] != ' '){
            end++;
        }
        reverse(s.begin()+start, s.begin()+end);
        start = end+1;
    }
}

int main(){
    vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};

    reverseWords(s);
    for(auto it: s){
        cout << it << " ";
    }
    
    return 0;
}
