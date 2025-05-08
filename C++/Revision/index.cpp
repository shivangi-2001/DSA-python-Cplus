#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int>& nums, int target){
    int s = 0;
    int e = nums.size()-1;

    while(s<=e){
        int mid=s+(e-s)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }

    return -1;
}

bool isPossible(vector<int>& nums, int mid, int k){
    int m=1;
    int page_sum =0;
    for(int i=0; i<nums.size(); i++){
        if(page_sum+nums[i] <= mid){
            page_sum+= nums[i];
        }else{
            m+=1;
            if(m>k || nums[i]>mid){
                return false;
            }
            page_sum=nums[i];
        }
    }
    return true;
}

int BookAllocation(vector<int>& nums, int k){
    int s =0;
    int e =0;
    for(int i=0; i<nums.size(); i++){
        e+=nums[i];
    }

    int ans = -1;
    while(s<=e){
        int mid=(s+e)/2;
        if(isPossible(nums, mid, k)){
            ans = mid;
            e = mid-1;
        }else{
            s=mid+1;
        }
    }

    return ans;
}


bool isPossibleAggressive(vector<int>& nums, int mid, int k){
    int m =1;
    int last = nums[0];

    for(int i=1; i<nums.size(); i++){
        if(last -nums[i] >= mid){
            m++;
            if(m == k){
                return true;
            }
            last = nums[i];
        }
    }

    return false;
}
int AggressiveCows(vector<int> nums, int cows){
    sort(nums.begin(), nums.end());

    int s = 0;
    int e = nums[nums.size()-1]-nums[0];

    int ans = -1;
    while (s<=e)
    {
        int mid = (s+e)/2;
        if(isPossibleAggressive(nums, mid, cows)){
            s = mid+1;
            ans = mid;
        }else{
            e = mid-1;
        }
    }
    return ans;
}


int kadane(vector<int>& nums){
    int maxi = nums[0];
    int sum =0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        maxi = max(maxi, sum);
        if(sum < 0){
            sum = 0;
        }
    }

    return maxi;
}

// void selectionSort(vector<int>& nums){
//     for(int i=0; i<nums.size(); i++){
//         int min = i;
//         for(int j=i+1; j<nums.size(); j++){
//             if(nums[j] < nums[min]){
//                 min = j;
//             }
//         }
//         swap(nums[min], nums[i]);
//     }
// }

int findMinIdex(vector<int>&nums, int min, int index, int size){
    int minIdex = min;
    for(int i=index; i<size; i++){
        if(nums[minIdex] > nums[i]){
            minIdex = i;
        }
    }

    return minIdex;
}

void selectionSort(vector<int>& nums, int index, int size){
    int minIndx = index;
    if(index > size){
        return;
    }
    minIndx = findMinIdex(nums, minIndx, index+1, size);
    swap(nums[minIndx],nums[index]);
    selectionSort(nums, index+1, size);
}

// void bubbleSort(vector<int>& nums){
//     for(int i=0; i<nums.size(); i++){
//         for(int j=0; j<nums.size()-i-1; j++){
//             if(nums[j+1] < nums[j]){
//                 swap(nums[j+1], nums[j]);
//             }
//         }
//     }
// }

void bubbleSort(vector<int>& nums, int size){
    if(size == 0 || size == 1){
        return;
    }
    for(int i=0; i<size-1; i++){
        if(nums[i+1] < nums[i]){
            swap(nums[i], nums[i+1]);
        }
    }
    bubbleSort(nums, size-1);
}

void insertionSort(vector<int>& nums){
    for(int i=1; i<nums.size(); i++){
        int key = nums[i];
        int j =i-1;

        while(j>=0 && nums[j] > key){
            nums[j+1] = nums[j];
            j-=1;
        }
        nums[j+1] = key;
    }
}

int GCD(int a, int b){
    if(b==0)
        return a;
    if(a == 0)
        return b;
    if (a == b)
        return a;

    if (a > b)
        return GCD(a - b, b);
    return GCD(a, b - a);
    // while(b!=0){
    //     int rem = a%b;
    //     a=b;
    //     b=rem;
    // }

    // return a;
}

int power(int a, int b){
    // if(b==0){
    //     return 1;
    // }
    // if(b==1){
    //     return a;
    // }
    // int ans = power(a, b/2);
    // if(b&1)
    //     return a * ans * ans;
    // else
    //     return ans * ans;

    int ans =1;
    while(b!=0){
        if(b&1){
            ans = a*ans;
        }
        a=a*a;
        b = b/2;
    }

    return ans;
}

void merge(vector<int>& nums, int s, int mid, int e){
    int t1 = mid-s+1;
    int t2 = e-mid;

    vector<int> n1(t1, 0);
    vector<int> n2(t2, 0);

    for(int i=0; i<t1; i++){
        n1[i]=nums[s+i];
    }

    for(int i=0; i<t2; i++){
        n2[i]=nums[mid+1+i];
    }


    int i=0, j=0, k=s;

    while(i<t1 && j<t2){
        if(n1[i] <= n2[j]){
            nums[k++] = n1[i++];
        }else{
            nums[k++] = n2[j++];
        }
    }

    while (i<t1)
    {
       nums[k++] = n1[i++];
    }

    while (i<t2)
    {
       nums[k++] = n2[i++];
    }
}
void mergeSort(vector<int>& nums, int s, int e){
        if(s >= e) return;
        int mid = (s+e)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        merge(nums, s, mid, e);
}  


int partition(vector<int>& arr, int s, int e){
    int pivot = arr[s];
    // count less the pivot element
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] < pivot){
            count ++;
        }
    }

    // place the pivot element at right place
    int pivotIndex = s+count;
    swap(arr[s], arr[pivotIndex]);

    // put element less than pivot at left
    // put element greater than pivot at right
    int i=s, j=e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] >= pivot){
            j--;
        }

        while(i<pivotIndex && j> pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void QuickSort(vector<int>& arr, int s, int e) {
    if(s >= e) return;

    int p = partition(arr, s, e);

    QuickSort(arr, s, p - 1);
    QuickSort(arr, p + 1, e);
}


int main(){
     // binary search
    // vector<int> nums = {3, 5, 18, 19, 99, 121};
    // int target = 99;
    // int index = binarySearch(nums, target);
    // cout << "Index at: " << index;


    // Book allocation - maximum no. of pages assigned to student is minized
    // vector<int> nums = {10, 20, 30, 40, 50};
    // int student = 2;
    // int index = BookAllocation(nums, student);
    // cout << "Ans: " << index;


    // agreesive cows - minimum distance between cow assigned to maximum
    // vector<int> nums = {4,2,1,3,6};
    // int cows = 2;
    // int index = AggressiveCows(nums, cows);
    // cout << "ans: " << index;


    //kadane's algorithm - max subarray
    // vector<int> nums = {-5,1,4,7,8};
    // int ans = kadane(nums);
    // cout << ans;


    // selection sort
    // vector<int> nums = {64, 25, 12, 22, 11};
    // selectionSort(nums, 0, nums.size());
    // for (size_t i = 0; i < nums.size(); i++)
    // {
    //    cout << nums[i] << " ";
    // }

    // bubble sort
    // vector<int> nums = {7, 12, 9, 11, 3};
    // bubbleSort(nums,  nums.size());
    // for (size_t i = 0; i < nums.size(); i++)
    // {
    //    cout << nums[i] << " ";
    // }

    // insertion sort
    // vector<int> nums = {7, 12, 9, 11, 3};
    // insertionSort(nums);
    // for (size_t i = 0; i < nums.size(); i++)
    // {
    //    cout << nums[i] << " ";
    // }

    // eulid Algorithn
    // int ans = GCD(75, 35);
    // cout << ans;

    // power
    // int ans = power(3,8);
    // cout << ans;

    // merge sort
    vector<int> nums = {4,1,6,0,10,99,56,78};
    mergeSort(nums, 0, nums.size()-1);
    for (size_t i = 0; i < nums.size(); i++)
    {
       cout << nums[i] << " ";
    }
    cout << endl;


    // Quick sort
    vector<int> arr = {2,4,14,41,67,100,79, 54,91};
    QuickSort(arr, 0, arr.size()-1);
    for (size_t i = 0; i < arr.size(); i++)
    {
       cout << arr[i] << " ";
    }


    
    return 0;
}