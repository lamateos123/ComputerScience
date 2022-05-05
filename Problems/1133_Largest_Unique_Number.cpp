#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
# 1133. Largest Unique Number
'''
Given an integer array nums, return the largest integer that only occurs once. 
If no integer occurs once, return -1.

 

Example 1:

Input: nums = [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: The maximum integer in the array is 9 but it is repeated. 
The number 8 occurs only once, so it is the answer.

Example 2:

Input: nums = [9,9,8,8]
Output: -1
Explanation: There is no number that occurs only once.
'''
*/

int largestUN(vector<int> nums){
    unordered_map<int,int> d;
    int ans = -1;
    for(int i=0; i<nums.size(); i++){
        d[nums[i]]++;
    }
    for(auto x:d){
        if (x.second==1) ans = max(ans,x.first);
    }
    return ans;
}

int main(){
    vector<int> nums;
    nums = {5,7,3,9,4,9,8,3,1};
    nums = {9,9,8,8};
    cout << largestUN(nums);
    return 0;
}