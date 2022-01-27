#include<iostream>
#include<vector>

using namespace std;

/*
# 26. Remove Duplicates from Sorted Array
#-----------------------------------------

#Example 1:
#Input: nums = [1,1,2]
#Output: 2, nums = [1,2,_]
#Explanation: Your function should return k = 2, with the first two 
#elements of nums being 1 and 2 respectively.
#It does not matter what you leave beyond the returned k 
#(hence they are underscores)

# Do not allocate extra space for another array. You must do this by 
# modifying the input array in-place with O(1) extra memory.

#Example 2:
#Input: nums = [0,0,1,1,1,2,2,3,3,4]
#Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
*/



int removeDuplicates(vector<int> &nums){
    int idiff = 0;
    int isame = 0;
    int counter = 0;
    for (int i=0; i<nums.size()-1; i++){
        if (nums[i] != nums[i+1]){
            counter++;
            idiff = i+1;
            nums[idiff-isame] = nums[idiff];
        } else {
            isame++;
        }
    }
    return counter+1;
}


int main(){
    vector<int> nums;
    nums = {1,1,2};
    int not_repeated = 0;
    cout << "Not repeated = " << removeDuplicates(nums) << endl;
    for (auto n:nums)cout << n << " ";
    cout << endl;

    nums = {0,0,1,1,1,2,2,3,3,4};
    cout << "Not repeated = " << removeDuplicates(nums) << endl;
    for (auto n:nums)cout << n << " ";

    return 0;
}
/*
~/github/ComputerScience/Problems$ ./26_Re_Sorted_Array s_from_
Not repeated = 2
1 2 2 
Not repeated = 5
0 1 2 3 4 2 2 3 3 4
*/