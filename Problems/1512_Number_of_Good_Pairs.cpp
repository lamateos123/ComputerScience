#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
# 1512. Number of Good Pairs
'''
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:

Input: nums = [1,2,3]
Output: 0
*/
int goodPairs(vector<int> nums){
    unordered_map<int, int> d;
    int num_good_pairs = 0;
    for (int i=0; i<nums.size(); i++){
        d[nums[i]]++;
    }

    for (auto x:d){
        if (x.second > 1){
            num_good_pairs = num_good_pairs + (x.second * (x.second-1) /2);
        } 
        cout << x.first << " " << x.second << endl;
    }
    return num_good_pairs;
}

int main(){
    vector<int> nums;
    nums = {1,2,3,1,1,3};
    //nums = {1,1,1,1};
    int ans = goodPairs(nums);
    cout << "Number of good pairs: " << ans << endl;
    return 0;
}
/*
~/github/ComputerScience/Problems$ ./1512_Number_of_Good_Pairs 
3 2
1 3
2 1
Number of good pairs: 4
*/