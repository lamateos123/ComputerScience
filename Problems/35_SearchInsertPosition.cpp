#include<iostream>
#include<vector>

using namespace std;

/*
# 35. Search Insert Position
'''
Given a sorted array of distinct integers and a target value, return the index 
if the target is found. If not, return the index where it would be if it were 
inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 
Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
'''
*/

int searchIP(vector<int> nums, int target){
    int l = 0;
    int r = nums.size()-1;
    int mid; 
    while (l<=r){
        mid = l + (r-l) / 2;
        if (target == nums[mid]) return mid;
        if (target > nums[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main(){
    vector<int> nums;
    int target;
    nums = {1,3,5,6}; 
    target = 5;
    cout << searchIP(nums, target)<< endl;;
    
    nums = {1,3,5,6}; 
    target = 2;
    cout << searchIP(nums, target)<< endl;;
    
    nums = {1,3,5,6}; 
    target = 7;
    cout << searchIP(nums, target)<< endl;;
    

    return 0;
}