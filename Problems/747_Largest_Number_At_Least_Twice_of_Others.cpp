#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/*
# 747. Largest Number At Least Twice of Others
'''
You are given an integer array nums where the largest integer is unique.

Determine whether the largest element in the array is at least twice as much as 
every other number in the array. If it is, return the index of the largest element, 
or return -1 otherwise.

 

Example 1:

Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.

Example 2:

Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.

Example 3:

Input: nums = [1]
Output: 0
Explanation: 1 is trivially at least twice the value as any other number because 
there are no other numbers.
'''
*/

int largestNumALTO(vector<int> nums){
    if (nums.size() == 1) return 0;
    int maxi = max_element(nums.begin(), nums.end())-nums.begin();
    int maxv = *max_element(nums.begin(), nums.end());
    for(auto i:nums) if((i*2 > maxv) && (i!=maxv)) return -1;
    return maxi;
}

int main(){
    vector<int> nums;
    nums = {3,6,1,0};
    cout << largestNumALTO(nums) << endl;

    nums = {1,2,3,4};
    cout << largestNumALTO(nums) << endl;
    return 0;
}