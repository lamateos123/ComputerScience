#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

/*
# 628. Maximum Product of Three Numbers
'''
Given an integer array nums, find three numbers whose product is maximum and 
return the maximum product.

Example 1:

Input: nums = [1,2,3]
Output: 6

Example 2:

Input: nums = [1,2,3,4]
Output: 24

Example 3:

Input: nums = [-1,-2,-3]
Output: -6
'''*/

int maxP(vector<int> nums){
    int ans = 0;
    sort(nums.begin(), nums.end());
    ans = max(nums[0]*nums[1]*nums[nums.size()-1], nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
    return ans;
}

int maxPO1(vector<int> nums){
    int min1 = INT32_MAX;
    int min2 = INT32_MAX;
    int max1 = INT32_MIN;
    int max2 = INT32_MIN;
    int max3 = INT32_MIN;
    for (auto i:nums){
        if (i <= min1){
            min2 = min1;
            min1 = i;
        }
        else if (i <= min2){
            min2 = i;
        }
        if (i >= max1){
            max3 = max2;
            max2 = max1;
            max1 = i;
        }
        else if (i >= max2){
            max3 = max2;
            max2 = i;
        }
        else if (i >= max3){
            max3 = i;
        }
    }
    return max(min1 * min2 * max1, max1 * max2 * max3);

}

int main() {
    vector<int> nums;
    nums = {1,2,3,4};
    cout << maxP(nums) << endl;
    nums = {1,2,3,4};
    cout << maxPO1(nums) << endl;
    return 0;
}
