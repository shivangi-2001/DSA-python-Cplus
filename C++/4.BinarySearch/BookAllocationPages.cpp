#include<iostream>
using namespace std;

bool isPossible(vector<int>& pages, int mid, int k){
    int m = 1;
    int sum = 0;
    for(int i=0; i<pages.size(); i++){
        if(sum + pages[i] <= mid){
            sum += pages[i];
        }else{
            m+=1;
            if(m>k || pages[i]>mid){
                return false;
            }
            sum = pages[i];
        }
    }

    return true;
}

int book_allocation_pages(vector<int>& pages, int student){
    int e = 0;
    for(int i=0; i<pages.size(); i++){
        e += pages[i];
    }
    int s = 0;
    int ans = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(pages, mid, student)){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int> pages = {10, 20, 30, 40};
    int student = 2;
    // Assign maximum pages to a student is minized
    int ans = book_allocation_pages(pages, student);
    cout << ans << endl;

    return 0;
}