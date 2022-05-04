#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
# 976. Largest Perimeter Triangle
'''
Given an integer array nums, return the largest perimeter of a triangle with a 
non-zero area, formed from three of these lengths. If it is impossible to form 
any triangle of a non-zero area, return 0.

a<= b<= c
a+b > c

Example 1:

Input: nums = [2,1,2]
Output: 5

Example 2:

Input: nums = [1,2,1]
Output: 0

'''
*/

int largestPT(vector<int> nums){
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i=0; i<nums.size()-2; i++){
        if (nums[i+2]+nums[i+1] > nums[i]){
            return nums[i+1]+nums[i+2]+nums[i];
        }        
    }
    return 0;
}

int main(){
    vector<int> nums;
    nums = {2,1,2};
    cout << largestPT(nums) << endl;
    return 0;
}