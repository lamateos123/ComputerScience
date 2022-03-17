#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
/*
# 1346. Check If N and Its Double Exist
#---------------------------------------
'''
Given an array arr of integers, check if there exists two integers N and M such 
that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

    i != j
    0 <= i, j < arr.length
    arr[i] == 2 * arr[j]

 
Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.

Example 2:

Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.

Example 3:

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.

'''
*/

bool checkDouble(vector<int> arr){
    sort(arr.begin(), arr.end());
    cout<<endl;
    for (auto i:arr){
        cout<<i<<",";
    }
    cout<<endl;

    for (int i=0; i < arr.size(); i++){
        for (int j=0; j<arr.size(); j++){
            if (arr[i]==arr[j]*2 and i!=j){
                return true;
            }
        }
    }
    return false;
}

bool checkDoubleSet(vector<int> arr){
    bool ans = false;
    int c = count(arr.begin(), arr.end(), 0);
    if (c>1) return true;

    set<int> s(arr.begin(),arr.end());

    for (int i=0; i<s.size(); i++){
        ans = s.find(2*i) != s.end();
        if (ans) return true;
    }
    return false;
}

int main(){
    vector<int> arr;
    arr = {10,2,5,3};
    //arr = {-2,0,10,-19,4,6,-8};
    //arr = {0,0};
    cout << boolalpha << checkDouble(arr);
    cout << boolalpha << checkDoubleSet(arr);
    return 0;
}