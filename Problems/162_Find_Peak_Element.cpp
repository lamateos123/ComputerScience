#include<iostream>
#include<vector>

using namespace std;

/*
# 162. Find Peak Element
'''
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -inf.

You must write an algorithm that runs in O(log n) time.

 
Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element 
is 2, or index number 5 where the peak element is 6.'''
*/

int findPeak(vector<int> nums){
    int l = 0;
    int r = nums.size()-1;
    long long int mid;
    while (l<r){
        mid = l + (r-l) / 2;
        if (nums[mid]<nums[mid+1]){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main(){
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << findPeak(nums) << endl;
    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./162_Find_Peak_Element 
5
*/