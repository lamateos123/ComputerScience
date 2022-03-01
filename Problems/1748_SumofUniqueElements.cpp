#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;
/*
# 1748. Sum of Unique Elements
'''
You are given an integer array nums. The unique elements of an 
array are the elements that appear exactly once in the array.

Return the sum of all the unique elements of nums.

Example 1:

Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.

Example 2:

Input: nums = [1,1,1,1,1]
Output: 0
Explanation: There are no unique elements, and the sum is 0.

Example 3:

Input: nums = [1,2,3,4,5]
Output: 15
Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.

'''
*/

int uniqueElements(vector<int> nums){
    int ans = 0;
    unordered_map <int,int> umap;
    for (auto n:nums){
        umap[n] += 1;
    }

    for (auto u:umap){
        cout <<u.first << ", " << u.second << endl;
        if (u.second == 1){
            ans += u.first;
        }
    }
    return ans;
}

int main(){
    vector<int> nums;
    nums = {1,2,3,2};
    //nums = {1,2,3,4,5};
    cout << uniqueElements(nums);
    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./1748_SumofUniqueElements 
3, 1
2, 2
1, 1
4
*/