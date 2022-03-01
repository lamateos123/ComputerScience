#include<iostream>
#include<vector>
using namespace std;

/*
# 1909. Remove One Element to Make the Array Strictly Increasing
#-----------------------------------------------------------------
'''
Given a 0-indexed integer array nums, return true if it can be made strictly 
increasing after removing exactly one element, or false otherwise. If the array 
is already strictly increasing, return true.

The array nums is strictly increasing if nums[i - 1] < nums[i] for each 
index (1 <= i < nums.length).

Example 1:

Input: nums = [1,2,10,5,7]
Output: true
Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.

Example 2:

Input: nums = [2,3,1,2]
Output: false
Explanation:
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.
'''
*/
bool strictlyUp(const vector<int> &nums){
    int c = 0;
    int idx = -1;

    for (int i=0; i<nums.size()-1; i++){
        if (nums[i] >= nums[i+1]){
            idx = i;
            c += 1;
        }
    }
    if (c == 0){
        return true;
    }

    if (c == 1){
        if (idx == 0 or idx == nums.size()-2){
            return true;
        }
        if (nums[idx-1] < nums[idx+1] or (idx+2 < nums.size() and nums[idx] < nums[idx+2])){
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums;
    nums = {105,924,32,968};//{2,3,1,2};
    cout << boolalpha << strictlyUp(nums);
}
/*
~/Desktop/ComputerScience/Problems$ ./1909_RemoveOneElementtoMaketheArrayStrictlyIncreasing 
true
*/