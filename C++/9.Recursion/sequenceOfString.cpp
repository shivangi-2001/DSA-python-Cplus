#include<iostream>
#include<string>
using namespace std;

void subsets(string str, vector<string>& output, int index, string& result){
    if(index >= str.length()){
        output.push_back(result);
        return;
    }

    subsets(str, output, index+1, result);

    char ele = str[index];
    result.push_back(ele);

    subsets(str, output, index+1, result);

    result.pop_back();
}

int main(){
    string str = "abc";
    string result = " ";
    vector<string> output;
    
    subsets(str, output, 0, result);

    for(auto it: output){
        cout << it << " ";
    }
    return 0;
}