#include<iostream>
#include<vector>

using namespace std;

/*
# 153. Find Minimum in Rotated Sorted Array
'''
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
For example, the array nums = [0,1,2,4,5,6,7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array 
[a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this 
array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
'''
*/

int minRotated(vector<int> nums){
    if (nums.size() == 1) return nums[0];

    int l = 0;
    int r = nums.size()-1;
    long long int mid;

    // IF the last element is greater than the first element 
    // THEN there is no rotation.
    // 1 < 2 < 3 < 4 < 5 < 7. Already sorted array
    if (nums[r] > nums[0]) return nums[0];

    while (l < r){
        mid = l + (r-l) / 2;
        // IF the mid element is greater than its next element mid+1 
        // THEN mid+1 element is the smallest
        // This point would be the point of change. From higher to lower value.
        if (nums[mid] > nums[mid+1]) return nums[mid+1];
        // IF the mid element is lesser than its previous element 
        // THEN mid element is the smallest
        if (nums[mid-1] > nums[mid]) return nums[mid];
        // IF mid element is greater than 0th element
        // THEN least value is still somewhere to the right
        if (nums[mid] > nums[0]) l = mid+1;
        // IF nums[0] is greater than the mid value 
        // THEN this means the smallest value is somewhere to the left
        else r = mid-1;        
    }
    return l;
}

int main(){
    vector<int> nums;
    nums = {3,4,5,1,2};
    cout << minRotated(nums) << endl;
    
    nums = {4,5,6,7,0,1,2};
    cout << minRotated(nums) << endl;
    
    nums = {11,13,15,17};
    cout << minRotated(nums) << endl;

    nums = {2,3,4,5,1};
    cout << minRotated(nums) << endl;
    
    return 0;
}
/*~/Desktop/ComputerScience/Problems$ ./153_Find_Minimum_in_Rotated_Sorted_Array 
1
0
11
1
*/