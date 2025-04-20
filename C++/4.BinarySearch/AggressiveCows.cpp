#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(vector<int>& distance, int mid, int cows){
    int k=1;
    int pos = distance[0];

    for(int i=0; i<distance.size(); i++){
        if(distance[i] - pos >= mid){
            k++;
            if(k == cows){
                return true;
            }
            pos = distance[i];
        }
    }

    return false;
}

int aggressiveCows(vector<int>& distance, int cows){
    sort(distance.begin(), distance.end());
    int maxi = *max_element(distance.begin(), distance.end());
    
    int s = 0;
    int e = maxi;
    int ans = -1;

    while (s<=e)
    {
       int mid = s+(e-s)/2;
       if(isPossible(distance, mid, cows)){
        
        ans = mid;
        s = mid+1;
       }else{
        e = mid-1;
       }
    }
    return ans;
}

int main(){
    vector<int> distance = {4,1,2,3, 6};
    int cows = 2;
    // arrange the cows in such a way that minimum distance as largest as possible
    int ans = aggressiveCows(distance, cows);
    cout << ans << endl;
    return 0;
}