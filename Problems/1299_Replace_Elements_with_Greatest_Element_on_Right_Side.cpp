#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
# 1299. Replace Elements with Greatest Element on Right Side
'''
Given an array arr, replace every element in that array with the greatest element among the elements to its right, 
and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation: 
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.

Example 2:

Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.

'''
*/

vector<int> repele(vector<int> arr){
    int n = arr.size()-1;
    int largest = arr[n];
    arr[n] = -1;
    n-=1;

    while(n>=0){
        if (arr[n]>largest){
            swap(arr[n], largest);
        } else {
            arr[n] = largest;
        }
        n-=1;
    }
    return arr;
}

/*
vector<int> repele(vector<int> arr){
    long long int pos = 0;
    for (long long int i=0; i<arr.size(); i++){
        pos = max_element(arr.begin()+(i+1),arr.end())-arr.begin();
        arr[i] = arr[pos];
        }

    arr[arr.size()-1]=-1;
    return arr;  
}
*/

int main() {
    vector<int> arr;
    vector<int> ans;
    arr = {17,18,5,4,6,1};
    ans = repele(arr);
    for (auto i:ans){
        cout << i << ", ";
    }
    return 0;
}