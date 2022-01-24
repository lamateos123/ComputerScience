#include<iostream>
#include<vector>

using namespace std;

/*
# 1929. Concatenation of Array
#--------------------------------

#Given an integer array nums of length n, you want to create an array ans of 
#length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
#Specifically, ans is the concatenation of two nums arrays.
#Return the array ans.

#Example 1:
#Input: nums = [1,2,1]
#Output: [1,2,1,1,2,1]
#Explanation: The array ans is formed as follows:
#- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
#- ans = [1,2,1,1,2,1]

#Example 2:
#Input: nums = [1,3,2,1]
#Output: [1,3,2,1,1,3,2,1]
#Explanation: The array ans is formed as follows:
#- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
#- ans = [1,3,2,1,1,3,2,1]

*/

vector<int> concatArray(vector<int> nums){
    vector<int> ans = nums;
    ans.insert(ans.end(), nums.begin(), nums.end());
    return ans;
}

vector<int> concatArray2(vector<int> nums){
    vector<int> ans(nums.size()*2,0);
    for (int i=0; i<nums.size(); i++){
        ans[i] = nums[i];
        ans[i+nums.size()] = nums[i];
    }
    return ans;
}


int main(){
    vector<int> nums;

    nums = {1,2,1};
    for (auto n:concatArray(nums)){
        cout << n << " ";
    }
    cout << endl;

   nums = {1,3,2,1};
    for (auto n:concatArray2(nums)){
        cout << n << " ";
    }

    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./1929_Concatenation_of_Array 
1 2 1 1 2 1 
1 3 2 1 1 3 2 1 
*/