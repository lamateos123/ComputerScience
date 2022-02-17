#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*


# 2006. Count Number of Pairs With Absolute Difference K
#-----------------------------------------------------------
'''
Given an integer array nums and an integer k, 
return the number of pairs (i, j) where i < j 
such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

    x if x >= 0.
    -x if x < 0.

Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]

Example 2:

Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.

'''
*/

int countPairs(const vector<int> &nums, int k){
    int c = 0;
    for (int i=0; i<nums.size(); i++){
        for(int j=0; j<nums.size(); j++){
            if ((i!=j) && (j>i) && (abs(nums[i]-nums[j])==k)){
                c+=1;
            }
        }
    }
    return c;
}

int countPairsImproved(const vector<int> &nums, int k){
    unordered_map<int, int> umap;
    int c = 0;
    for (auto num:nums){
        umap[num]+=1;
    }
    unordered_map<int, int>::const_iterator got;
    for (auto num:nums){
        got = umap.find(num+k);
        if (got != umap.end()){
            c += umap[num+k];
        }
    }
    return c;
}

int main(){
    vector<int> nums = {1,2,2,1};
    int k = 1;
    //cout << countPairs(nums, k);
    cout << countPairsImproved(nums, k);
    return 0;
}