#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPlaindrome(string s){
    int start = 0;
    int end = s.size()-1;

    while(start < end){
        if(s[start++] != s[end--]){
            return false;
        }
    }

    return true;
}

char ToLowercase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else{
        return ch - 'A' + 'a';
    }
}

int main(){
    string ch=" ";
    int s = 0;

    string input;
    while (s < ch.size())
    {   
        if(isalnum(ch[s])){
            input += ToLowercase(ch[s]);
        }
        s++;
    }

    // converted output
    cout << input << endl;


    // return palidnrome answer
    bool ans = isPlaindrome(input);
    cout << ans;
    
    return 0;
}