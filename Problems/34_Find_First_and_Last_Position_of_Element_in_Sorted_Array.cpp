#include<iostream>
#include<vector>

using namespace std;

/*
# 34. Find First and Last Position of Element in Sorted Array
'''
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
'''
*/

int findBound(vector<int> nums, int target, bool isFirst){
    int N = nums.size();
    int l = 0;
    int r = N-1;
    int mid;
    while (l<=r){
        mid = l + (r-l) / 2;
        if (nums[mid]==target){
            if (isFirst){
                if ((mid==l) or (nums[mid-1]<target)) return mid;
            r=mid-1;
            } else {
                if ((mid==r) or (nums[mid+1]>target)) return mid;
            l=mid+1;  
            }      
        }
        else if (nums[mid] < target) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

vector<int> searchRange(vector<int> nums, int target){
    int lower = findBound(nums, target, true);
    if (lower == -1) return {-1,-1};
    int upper = findBound(nums, target, false);
    return {lower,upper};
}

/*
vector<int> searchRange(vector<int> nums, int target){
    int a = 0;
    int b = 0;
    if ((nums.size()==1) and nums[0]==target) return {0,0};
    if ((nums.size()==1) and nums[0]!=target) return {-1,-1};
    for (int i=0;i<nums.size();i++){
        if (nums[i]==target){
            a=i;
            for (int j=nums.size()-1;j>=0;j--){
                if(nums[j]==target){
                    b=j;
                    return{a,b};
                }
            }
        }
    }
    return {-1,-1};
}
*/
int main(){
    vector<int> nums;
    vector<int> ans;
    int target;
    nums = {5,7,7,8,8,10};
    target = 8;
    ans = searchRange(nums, target);
    cout << "[";
    int x=0; // counter for displaying 
    for (auto i:ans){
        if (x==0) {
            cout << i << ',';
        } else {
            cout << i;
        }
        x++;
    }
    cout << "]" << endl;
    return 0;
}