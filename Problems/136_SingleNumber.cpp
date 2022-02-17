#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
# 136. Single Number
'''
Given a non-empty array of integers nums, every element appears 
twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and 
use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

'''
*/

int singleNumber(const vector<int> &nums){
    unordered_map <int, int> umap;
    for (auto n:nums){
        umap[n]+=1;
    }
    for (auto i:umap){
        if (i.second == 1){
            return i.first;
        }
    }
    return 0;
}

int main(){
    vector<int> nums;
    nums = {4,1,2,1,2};
    cout << singleNumber(nums);
    return 0;
}