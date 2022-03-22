#include<iostream>
#include<vector>

using namespace std;

/*
# 53. Maximum Subarray
'''
Given an integer array nums, find the contiguous subarray (containing 
at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
'''
*/

int maxSubArray(vector<int> nums){
    int suma = nums[0];
    int ans = nums[0];
    int i = 1;

    while(i < nums.size()){
        suma = max(nums[i], suma + nums[i]);
        ans = max(suma,ans);
        i++;
    }
    return ans;
}

int main(){
    vector<int> nums;
    
    nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;

    nums = {1};
    cout << maxSubArray(nums) << endl;

    nums = {5,4,-1,7,8};
    cout << maxSubArray(nums) << endl;
    return 0;
}

/*
~/github/ComputerScience/Problems$ ./53_Maximum_Subarray 
6
1
23
*/