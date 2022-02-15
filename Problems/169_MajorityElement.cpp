#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
# 169. Majority Element
'''
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ 
times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

'''
*/

vector<int> nums;

int majorityElement(vector<int> nums){
    unordered_map<int, int> umap;
    for (auto n:nums){
        umap[n]++;
        if (umap[n] > nums.size()/2){
            return n;
        }
    }
    return 0;
}

int main(){
    nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums);
    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./169_MajorityElement 
2
*/