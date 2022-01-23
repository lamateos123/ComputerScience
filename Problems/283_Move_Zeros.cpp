#include<iostream>
#include<vector>
using namespace std;

/*
# 283. Move Zeros
# -----------------

#Given an integer array nums, move all 0's to the end of it while maintaining 
#the relative order of the non-zero elements.

#Note that you must do this in-place without making a copy of the array.

#Example 1:
#Input: nums = [0,1,0,3,12]
#Output: [1,3,12,0,0]

#Example 2:
#Input: nums = [0]
#Output: [0]
*/
vector<int> movez(vector<int> nums){
    // step 1. count the zeros
    //         separate the non zero digit
    // step 2. pushback the zeros 
    int count_zeros = 0;
    vector<int> non_zero = {};

    //count zeros
    for(int i=0; i<nums.size(); i++){
        cout << i << "=" << nums[i] << endl;
        if (nums[i] == 0){
            count_zeros++;
        } else {
            non_zero.push_back(nums[i]);
        }
    }
    cout << "Zeros" << count_zeros << endl;
    for (auto x:non_zero){
        cout << x << endl;
    }

    //move all the zeros to the end
    for(int i=0; i<count_zeros; i++){
        cout << i << endl;
        non_zero.push_back(0);
    }

    nums = non_zero;

    for (auto x:nums){
        cout << x << ",";
    }

    return nums;
}

vector<int> movez_optimal(vector<int> nums){
    // Set a couple of indexes
    // the current and the non zero digits
    // if non zero digit is detected then swap last non zero with current
    int last_non_zero_found_at = 0;
    for(int cur=0; cur<nums.size(); cur++){
        if(nums[cur] != 0){
            int temp = nums[last_non_zero_found_at];
            nums[last_non_zero_found_at] = nums[cur];
            nums[cur] = temp;
            last_non_zero_found_at++;
        }
    }
    return nums;
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    movez(nums);

    cout << endl;
    nums = {0,1,0,3,12};
    nums = movez_optimal(nums);
    for(auto x:nums){
        cout << x << ",";
    }

    return 0;
}