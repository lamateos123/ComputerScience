#include<iostream>
#include<vector>
using namespace std;

/*
# 1313. Decompress Run-Length Encoded List
#--------------------------------------------
'''
We are given a list nums of integers representing a list compressed 
with run-length encoding.

Consider each adjacent pair of elements 
[freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  
For each such pair, there are freq elements with value val 
concatenated in a sublist. Concatenate all the sublists from 
left to right to generate the decompressed list.

Return the decompressed list.

Example 1:

Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4] is [2,4,4,4].

Example 2:

Input: nums = [1,1,2,3]
Output: [1,3,3]

'''
*/

vector<int> decompressEL(vector<int> nums){
    vector<int> ans = {};
    for (int i=1; i<nums.size(); i+=2){
        for (int j=1;j<=nums[i-1]; j++){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> nums;
    vector<int> ans;
    nums = {1,2,3,4};
    ans = decompressEL(nums);
    for (auto a:ans){
        cout << a << ",";
    }
    return 0;
}
/*
~/github/ComputerScience/Problems$ ./1287_Element_Appearing_More_Than_25p_In_Sorted_Array 
2,4,4,4
*/