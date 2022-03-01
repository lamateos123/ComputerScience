#include<iostream>
#include<vector>
using namespace std;
/*
# 605. Can Place Flowers
'''
You have a long flowerbed in which some of the plots are planted, 
and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means 
empty and 1 means not empty, and an integer n, return if n new flowers 
can be planted in the flowerbed without violating the no-adjacent-flowers rule.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

'''
*/

bool flowers(const vector<int> &flowerbed, int n){
    int c = 0;
    vector<int> nums = flowerbed;    

    if (nums.size() == 1){
        if (nums[0]==0){
            if (n!=0){
                c+=1;
            } else {
                return true;
            }
        }
    }

    if (nums.size() > 1){
        if (nums[0]==0 && nums[1]==0){
            nums[0]=1;
            c+=1;
        }
        if (nums[-1]==0 && nums[-2]==0){
            nums[-1]=1;
            c+=1;
        }
        for (int i=1; i < nums.size()-1; i++){
            if (nums[i-1]==0 && nums[i]==0 && nums[i+1]==0){
                nums[i]=1;
                c+=1;
            }
        }
    }
    return c>=n;
}

int main(){
    vector<int> flowerbed;
    int n;
    flowerbed = {1,0,0,0,1};
    n = 1;
    cout << boolalpha << flowers;
    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./605_CanPlaceFlowers 
true
*/