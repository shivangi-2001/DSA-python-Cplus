#include<iostream>
#include<string>
using namespace std;

void reverseString(string& str, int start, int end){
    if(start > end){
        return;
    }
    swap(str[start++], str[end--]);

    reverseString(str, start,  end);

}

int main(){
    string str = "shivangi";
    reverseString(str, 0, str.length()-1);

    cout << str;
    return 0;
}