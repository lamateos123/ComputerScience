#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
# 1150. Check If a Number Is Majority Element in a Sorted Array
'''
Given an integer array nums sorted in non-decreasing order and 
an integer target, return true if target is a majority element, 
or false otherwise.

A majority element in an array nums is an element that appears 
more than nums.length / 2 times in the array.

Example 1:

Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.

'''
*/

bool majorElement(vector<int> nums, int target){
    int c = 0;
    for (auto n:nums){
        if(n != target){
            c += 1;
        }
    if (nums.size()/2 > c){
        return true;
    }
    }
    return false;
}

bool majorElementUMap(vector<int> nums, int target){
    int c = 0;
    unordered_map<int, int> umap;
    for (auto n:nums){
        umap[n]++;
        }

    for (auto i:umap){
        cout << i.first << ","<< i.second << endl;
    }
    if (nums.size()/2 < umap[target]){
        return true;
    }
    return false;
}

int main(){
    vector<int> nums ={2,4,5,5,5,5,5,6,6};
    int target = 5;
    cout << "with List" << endl;
    cout << boolalpha << majorElement(nums, target);
    cout << endl << "with UMap" << endl;
    cout << boolalpha << majorElementUMap(nums, target);
    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./1150_CheckIfaNumberIsMajorityElementinaSortedArray 
with List
true
with UMap
6,2
5,5
4,1
2,1
true
*/