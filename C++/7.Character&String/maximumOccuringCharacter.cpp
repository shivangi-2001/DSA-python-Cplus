#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    string s = "banAna";
    unordered_map<char, int> mp;

    int start = 0;
    while(start < s.size()){
        s[start] = tolower(s[start]);
        if(mp.find(s[start]) != mp.end()){
            mp[s[start]]++;
        }else{
            mp[s[start]] = 1;
        }

        start++;
    }

    for(auto it:mp){
        cout << it.first <<" -> "<< it.second << endl;
    }

    int max = 0;
    char ans;

    for(auto it:mp){
        if(max < it.second){
            ans = it.first;
            max = it.second;
        }
    }

    cout << "Maximum occuring character: " << ans << "-" << max;
    return 0;
}