#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

string replaceWords(vector<string> dictionary, string sentence){
    string word, result;
    istringstream ss(sentence);
    unordered_set<string> dict(dictionary.begin(), dictionary.end());

    while (ss >> word)
    {
        string prefix = "";
        for(int i=1; i<= word.length(); i++){
            prefix = word.substr(0, i);
            if(dict.count(prefix)){
                word = prefix;
                break;
            }
        }

        result += word + " ";
    }
    
    result.pop_back();
    return result;

}

int main(){
    vector<string> dictionary = {"a","b","c"};
    string sentence = "aadsfasf absbs bbab cadsfafs";

    string ans = replaceWords(dictionary, sentence);

    cout << ans;
    return 0;

}