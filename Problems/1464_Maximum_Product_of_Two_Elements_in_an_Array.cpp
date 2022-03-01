#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
# 1464. Maximum Product of Two Elements in an Array
#--------------------------------------------------
'''
Given the array of integers nums, you will choose two different indices i and j 
of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get 
the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the 
maximum value of (5-1)*(5-1) = 16.

Example 3:

Input: nums = [3,7]
Output: 12

'''
*/

int maxP(vector<int> nums){
    int ans = 0;
    int taken = 0;
    int max_number1 = 0;
    int max_number2 = 0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i] > max_number1){
            max_number1 = nums[i];
            taken = i;
        }
    }
    for (int i=0; i<nums.size(); i++){
        if ((i != taken) && (nums[i] > max_number2)){
            max_number2 = nums[i];
        }
    }
    cout << "number1: " << max_number1 << " numbers2: " << max_number2 << endl;
    ans = (max_number1 - 1) * (max_number2 - 1);
    return ans;
}

int maxP2(vector<int> nums){
    sort(nums.begin(), nums.end(), greater<int>());
    for (auto num:nums){
        cout << num << ",";
    }
    return (nums[0]-1) * (nums[1]-1);
}

int main(){
    vector<int> nums;
    nums = {3,4,5,2};
    cout << maxP2(nums);
    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./1464_Maximum_Product_of_Two_Elements_in_an_Array 
number1: 5 numbers2: 4
12
*/