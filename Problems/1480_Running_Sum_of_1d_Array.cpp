#include<iostream>
#include<vector>

using namespace std;

/*
# 1480. Running Sum of 1d Array
#------------------------------

#Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
#Return the running sum of nums.

#Example 1:
#Input: nums = [1,2,3,4]
#Output: [1,3,6,10]
#Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

#Example 2:
#Input: nums = [1,1,1,1,1]
#Output: [1,2,3,4,5]
#Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

#Example 3:
#Input: nums = [3,1,2,10,1]
#Output: [3,4,6,16,17]
*/

vector<int> running_sum(vector<int> nums){
    int suma = 0;
    for (int i=0; i < nums.size(); i++){
        suma += nums[i];
        nums[i] = suma;
    }
    return nums;
}    

vector<int> running_sum_optimal(vector<int> nums){
    for (int i=1; i<nums.size(); i++){
        nums[i]+=nums[i-1];
    }
    return nums;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};

    nums = running_sum(nums);
    for(auto n:nums){
        cout << n << " ";
    }
    cout << endl;

    nums = {1,1,1,1,1};
    nums = running_sum_optimal(nums);
    for(auto n:nums){
        cout << n << " ";
    }

    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./1480_Running_Sum_of_1d_Array 
1 3 6 10 
1 2 3 4 5 
*/