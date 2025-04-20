
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;


// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...

// AAA -> 26*26*1+26*1+1 => 26(26*1+1)+1
 

int titleToNumber(string columnTitle) {
    long int unit = 1;
    int ans = 0;

    for(int i = columnTitle.size() - 1; i >= 0; i--) {
        int place = columnTitle[i] - 'A' + 1;
        ans += unit * place;
        unit *= 26;
    }

    return ans;
}

int main(){
    
    return 0;
}