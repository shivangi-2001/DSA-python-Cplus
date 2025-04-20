#include<iostream>
#include<string>

using namespace std;

int main(){

    string s;
    cin >> s;

    s[3] = '\0';

    cout << s << endl;

    char ch[19];
    cin >> ch;

    ch[3] = '\0';

    cout << ch;

    return 0;
}