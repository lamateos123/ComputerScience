#include<iostream>
#include<vector>

using namespace std;

/*
# 905. Sort Array By Parity
'''
Given an integer array nums, move all the even integers at the beginning of 
the array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Example 2:

Input: nums = [0]
Output: [0]

'''
*/

vector<int> nums;

vector<int> sortbyParity(vector<int>nums){
    int i = 0;
    int j = nums.size()-1;
    int temp;
    while (i<j){
        if (nums[i]%2 == 1 and nums[j]%2 == 0){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        if (nums[i]%2 == 0) i+=1;
        if (nums[j]%2 == 1) j-=1;
    }
    return nums;
}

int main(){
    nums = {3,1,2,4};
    nums = sortbyParity(nums);
    cout << endl;
    for(auto i:nums){
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}