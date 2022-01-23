#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
# 217. Contains Duplicate
#---------------------------
# Given an integer array nums, return true if any value appears at least twice
# in the array, and return false if every element is distint

# Example 1:
#Input: nums = [1,2,3,1]
#Output: true

#Example 2:
#Input: nums = [1,2,3,4]
#Output: false

#Example 3:
#Input: nums = [1,1,1,3,3,4,3,2,4,2]
#Output: true
*/

bool contains_duplicate(vector<int> nums){
    unordered_map<int,int> d;
    for (auto n:nums){
        d[n]++;
        cout << d[n] << endl;
        if (d[n] > 1) {
            return true;
        }
    }
    return false;
}


int main(){
    vector<int> nums;
    nums = {1,2,3,1};
    cout << boolalpha << contains_duplicate(nums) << endl;

    nums = {1,2,3,4};
    cout << boolalpha << contains_duplicate(nums) << endl;

    nums = {1,1,1,3,3,4,3,2,4,2};
    cout << boolalpha << contains_duplicate(nums) << endl;


}

/*
:~/github/ComputerScience/Problems$ ./217_Contains_Duplicate 
1
1
1
2
true
1
1
1
1
false
1
2
true
*/