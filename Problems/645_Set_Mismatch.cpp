#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
# 645. Set Mismatch
'''
You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another 
number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after 
the error.

Find the number that occurs twice and the number that is missing and return them in 
the form of an array.

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:

Input: nums = [1,1]
Output: [1,2]
'''
*/

vector<int> sMis(vector<int> nums){
    vector<int> ans;
    for (int i =1; i<nums.size()+1; i++){
        cout << i << nums[i-1] << endl;
        if (nums[i-1] != i){
            ans.push_back(nums[i-1]);
            ans.push_back(i);
            return ans;
        }
    }
    return ans;
}

vector<int> sMisd(vector<int> nums){
    unordered_map<int,int> d;
    vector<int> ans;
    for (auto i:nums){
        d[i] += 1;
    }
    for (auto kv:d){
        if (kv.second == 2){
            ans.push_back(kv.first);
            ans.push_back(kv.first + 1);
            return ans;
        }
    }
    return ans;
}

int main(){
    vector<int> nums;
    vector<int> ans;

    nums = {1,2,2,4};
    ans.clear();
    ans = sMis(nums);
    for (auto i:ans){
        cout << i << ",";
    }

    cout << endl;

    nums = {1,1};
    ans.clear();
    ans = sMis(nums);
    for (auto i:ans){
        cout << i << ",";
    }

    cout << endl;
    cout << endl;
    // solution with dictionary (unordered_map)
    nums = {1,2,2,4};
    ans.clear();
    ans = sMisd(nums);
    for (auto i:ans){
        cout << i << ",";
    }

    cout << endl;

    nums = {1,1};
    ans.clear();
    ans = sMisd(nums);
    for (auto i:ans){
        cout << i << ",";
    }

}
/*
~/Desktop/ComputerScience/Problems$ ./645_Set_Mismatch 
11
22
32
2,3,
11
21
1,2
*/