#include<iostream>
#include<vector>

using namespace std;

/*
# 922. Sort Array By Parity II
'''
Given an array of integers nums, half of the integers in nums are odd, 
and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever 
nums[i] is even, i is even.

Return any answer array that satisfies this condition.

Example 1:

Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been 
accepted.

Example 2:

Input: nums = [2,3]
Output: [2,3]
'''
*/

vector<int> sortParity(vector<int> nums){
    vector<int> ans;
    vector<int> ans_even;
    vector<int> ans_odd;
    int even = 0;
    int odd = 0;

    for(auto n:nums){
        if(n%2 == 0) ans_even.push_back(n);
        else ans_odd.push_back(n);
    }
    for(int i=0; i<nums.size()/2; i++){
        ans.push_back(ans_even[i]);
        ans.push_back(ans_odd[i]);
    }
    return ans;
}


vector<int> sortParity2(vector<int> nums){
    int t;
    int N = nums.size();
    vector<int> ans(N,-1);

    t=0;
    for (auto i:nums){
        if (i%2==0){
            ans[t] = i;
            t+=2;
        }
    }

    t=1;
    for (auto j:nums){
        if (j%2!=0){
            ans[t] = j;
            t+=2;
        }
    }
    return ans;
}

vector<int> sortParity3(vector<int> nums){
    int j = 1;
    for (int i=0; i< nums.size(); i+=2){
        if (nums[i]%2){
            while (nums[j]%2){
                j+=2;
            }
            swap(nums[i],nums[j]);
        }
    }
    return nums;
}

int main(){
    vector<int> nums;
    vector<int> ans;
    nums = {4,2,5,7};
    ans = sortParity(nums);
    cout << endl;
    for(auto i:ans){
        cout << i << ",";
    }
    cout << endl;

    nums = {4,2,5,7};
    ans = sortParity2(nums);
    cout << endl;
    for(auto i:ans){
        cout << i << ",";
    }
    cout << endl;

    nums = {4,2,5,7};
    ans = sortParity3(nums);
    cout << endl;
    for(auto i:ans){
        cout << i << ",";
    }
    cout << endl;

    return 0;
}