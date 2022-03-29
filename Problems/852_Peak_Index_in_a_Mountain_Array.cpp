#include<iostream>
#include<vector>
using namespace std;

/*
# 852. Peak Index in a Mountain Array
'''
Let's call an array arr a mountain if the following properties hold:

    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... arr[i-1] < arr[i]
        arr[i] > arr[i+1] > ... > arr[arr.length - 1]

Given an integer array arr that is guaranteed to be a mountain, return any i 
such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > 
arr[arr.length - 1].

 
Example 1:

Input: arr = [0,1,0]
Output: 1

Example 2:

Input: arr = [0,2,1,0]
Output: 1

Example 3:

Input: arr = [0,10,5,2]
Output: 1
'''
*/

int mountainPeak(vector<int> arr){
    for (int i=0; i<arr.size(); i++){
        if (arr[i]>arr[i+1]){
            return i;
        }
    }
}

int mountainPeakBin(vector<int> arr){
    int l = 0;
    int r = arr.size()-1;
    int mid;
    while (l<r){
        mid = l + (r - l) / 2;
        if (arr[mid] < arr[mid+1]){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main(){
    vector<int> arr;
    arr = {0,2,1,0};
    cout << "the peak is at index=" << mountainPeak(arr) << endl;
    cout << "the peak is at index=" << mountainPeakBin(arr) << endl;
    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./852_Peak_Index_in_a_Mountain_Array 
the peak is at index=1
the peak is at index=1
*/