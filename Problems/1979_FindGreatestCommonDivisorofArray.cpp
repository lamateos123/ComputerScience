#include<iostream>
#include<vector>

using namespace std;

/*
# 1979. Find Greatest Common Divisor of Array
#---------------------------------------------
'''
Given an integer array nums, return the greatest common divisor 
of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive 
integer that evenly divides both numbers.

Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
*/

int gcda(const vector<int> &nums){
    int mini = 1001;
    int maxi = 0;
    int lcm = 1;

    for(auto n:nums){
        if (n<=mini) mini = n;
        if (n>=maxi) maxi = n;        
    }
    //cout << mini << " " << maxi << endl;
    //for(int i=mini+1; i>=1; i--){
    for (int i=2; i<=maxi; i++){
        //cout << maxi%i << " " << mini%i << " " << i << endl;
        if((maxi%i == 0) and (mini%i == 0)){
            lcm = i;
        }
    }
    return lcm;
}

int main(){
    vector<int> nums = {2,5,6,9,10};
    nums = {7,5,6,8,3};
    cout << gcda(nums) ;
    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./1979_FindGreatestCommonDivisorofArray 
3 8
0 3 4
2 0 3
0 1 2
0 0 1
1
*/