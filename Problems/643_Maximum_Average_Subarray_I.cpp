#include<iostream>
#include<vector>

using namespace std;

/*
# 643. Maximum Average Subarray I
'''
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum 
average value and return this value. Any answer with a calculation error less 
than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:

Input: nums = [5], k = 1
Output: 5.00000

'''
*/

float maxA(vector<int> nums, int k){
    int ans = INT32_MIN;
    int suma = 0;
    int i = 0;
    for (int j=0; j < nums.size(); j++){
        suma += nums[j];
        if (j-i+1 == k){
            ans = max(ans, suma);
            suma -= nums[i];
            i++;
        }
    }
    return (double)ans/k;
}
int main(){
    vector<int> nums;
    int k;
    nums = {1,12,-5,-6,50,3};
    k = 4;
    cout << maxA(nums, k) << endl;

    return 0;
}
