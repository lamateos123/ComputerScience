#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
# 2164. Sort Even and Odd Indices Independently
'''
You are given a 0-indexed integer array nums. Rearrange the values of nums 
according to the following rules:

    Sort the values at odd indices of nums in non-increasing order.
        For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. 
        The values at odd indices 1 and 3 are sorted in non-increasing order.
    Sort the values at even indices of nums in non-decreasing order.
        For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. 
        The values at even indices 0 and 2 are sorted in non-decreasing order.

Return the array formed after rearranging the values of nums.

 

Example 1:

Input: nums = [4,1,2,3]
Output: [2,3,4,1]
Explanation: 
First, we sort the values present at odd indices (1 and 3) in non-increasing order.
So, nums changes from [4,1,2,3] to [4,3,2,1].
Next, we sort the values present at even indices (0 and 2) in non-decreasing order.
So, nums changes from [4,1,2,3] to [2,3,4,1].
Thus, the array formed after rearranging the values is [2,3,4,1].

'''
*/

vector<int> sortEO(vector<int> nums){
    vector<int> ans;
    vector<int> ans_even;
    vector<int> ans_odd;
    int start = 0; //0 for even, 1 for odd

    for (int i=0; i<nums.size(); i++){
        if (i%2==0) ans_even.push_back(nums[i]);
        else ans_odd.push_back(nums[i]);
    }

    sort(ans_odd.begin(), ans_odd.end(), greater<int>());
    sort(ans_even.begin(), ans_even.end());

    if (ans_even.size() > ans_odd.size()){
        ans.push_back(ans_even[0]);
        ans_even.erase(ans_even.begin());
        start = 1;
    } 
    else if (ans_even.size() < ans_odd.size()) {
        ans.push_back(ans_odd[0]);
        ans_odd.erase(ans_odd.begin());
    }

    for (int i=0;i<ans_even.size(); i++){
        if (start == 0){
            ans.push_back(ans_even[i]);
            ans.push_back(ans_odd[i]);
        } else {
            ans.push_back(ans_odd[i]);
            ans.push_back(ans_even[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> ans;
    vector<int> nums;
    nums = {4,1,2,3};
    ans = sortEO(nums);

    cout << endl;
    for (auto i:ans){
        cout << i << ',';
    }
    cout << endl;

    return 0;
}