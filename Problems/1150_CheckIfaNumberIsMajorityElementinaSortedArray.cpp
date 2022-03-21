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

        c = 0
        for n in nums:
            if n != target:
                c += 1
        if len(nums)/2 > c:
            return True
        return False

*/

bool majorElement(vector<int> nums, int target){

    int n = nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i] == target) count++;
    }
    if(count > n/2) return true;

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
    vector<int> nums;// ={2,4,5,5,5,5,5,6,6};
    nums = {10,100,101,101};

    int target = 101;//5;
    cout << "with List" << endl;
    cout << boolalpha << majorElement(nums, target);
    cout << endl << "with UMap" << endl;
    cout << boolalpha << majorElementUMap(nums, target);
    return 0;
}

/*
~/github/ComputerScience/Problems$ ./1150_CheckIfaNumberIsMajorityElementinaSortedArray 
with List
false
with UMap
100,1
101,2
10,1
false
*/