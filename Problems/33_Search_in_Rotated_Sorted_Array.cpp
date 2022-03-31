#include<iostream>
#include<vector>
using namespace std;

/*
# 33. Search in Rotated Sorted Array
'''
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown 
pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], 
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return 
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

'''
*/

int searchRotate(vector<int> nums, int target){
    int l = 0;
    int r = nums.size()-1;
    long long int mid;

    while(l <= r){
        mid = l + (r-l) / 2;
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[mid] >= nums[l]){
/*                         x
                         x x
                       x x x
                     x x x x
                   x x x x x 
                 x x x x x x       
                 x x x x x x     x 
                 x x x x x x   x x 
                 3 4 5 6 7 8 0 1 2 
                 l       m        r
*/
            if ((target >= nums[l]) and (target < nums[mid])){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
/*                 x
                 x x
                 x x             x
                 x x           x x
                 x x         x x x 
                 x x       x x x x      
                 x x     x x x x x 
                 x x   x x x x x x 
                 7 8 0 1 2 3 4 5 6
                 l       m       r
*/            
            if ((target <= nums[l]) and (target < nums[mid])){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << searchRotate(nums, target) << endl;

    nums = {4,5,6,7,0,1,2};
    target = 3;
    cout << searchRotate(nums, target) << endl;
    
    nums = {1};
    target = 0;
    cout << searchRotate(nums, target) << endl;
    
    nums = {1,3,5};
    target = 1;
    cout << searchRotate(nums, target) << endl;
    
    return 0;
}
/*
/Desktop/ComputerScience/Problems$ ./33_Search_in_Rotated_Sorted_Array 
4
-1
-1
0
*/