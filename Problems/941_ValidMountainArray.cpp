#include<iostream>
#include<vector>

using namespace std;

/*
# 941. Valid Mountain Array
#----------------------------
'''
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Example 1:

Input: arr = [2,1]
Output: false

Example 2:

Input: arr = [3,5,5]
Output: false

Example 3:

Input: arr = [0,3,2,1]
Output: true

'''
*/
bool validMountain(const vector<int> &arr){
    int peak = 0;
    int up = 0;

    //mountain of less than 3 points doesn't exist
    if (arr.size() < 2) return false;

    for (int i=0; i<arr.size()-1; i++){
        // valley detected
        if (arr[i] == arr[i+1]) return false;
        // stating going downhill
        if (arr[i] > arr[i+1] && up == 0) return false;
        // moving up until hill
        if (arr[i] < arr[i+1] && peak == 0) up = 1;
        // moving up twice
        if (arr[i] < arr[i+1] && peak != 0) return false;
        // moving down
        if (arr[i] > arr[i+1]){
            up = -1;
            peak = -1;
        }
    }
    if (up == -1) return true;
}

int main(){
    vector<int> arr = {0,3,2,1};
    cout << boolalpha << validMountain(arr);
    return 0;
}
/*
~/github/ComputerScience/Problems$ ./941_ValidMountainArray 
true
*/