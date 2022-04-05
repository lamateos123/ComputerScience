#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
# 485. Max Consecutive Ones
'''
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. 
The maximum number of consecutive 1s is 3.

Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
'''
*/

int maxConOnes(vector<int> nums){
    int maxi = 0;
    int c = 0;
    for (auto i:nums){
        if (i == 1) {
            c++;
        } else {
            if (c > maxi){
                maxi = c;
            }
            c = 0;
        }
    }
    maxi = max(maxi,c);
    return maxi;
}

int main(){
    vector<int> nums;
    
    nums = {1,1,0,1,1,1};
    cout << maxConOnes(nums) << endl;

    nums = {1,0,1,1,0,1};
    cout << maxConOnes(nums) << endl;
    return 0;
}