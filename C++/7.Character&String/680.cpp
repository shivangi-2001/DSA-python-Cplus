#include<iostream>
#include<string>

using namespace std;
// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

bool isPlaindrome(string s, int left, int right){
    while(left< right){
        if(s[left++] != s[right--]){
            return false;
        }
    }
    return true;
}

bool ValidPalindrome(string s){
    int start = 0;
    int end = s.size()-1;
    while(start < end){
        if(s[start] != s[end]){
            return isPlaindrome(s, start+1, end) || isPlaindrome(s, start, end-1);
        }
        start++;
        end--;
    }

    return true;
}



int main(){
    string s = "aca";
    bool ans = ValidPalindrome(s);

    cout << ans;
    return 0;
}