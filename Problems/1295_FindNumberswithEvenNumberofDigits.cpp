#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

/*
# 1295. Find Numbers with Even Number of Digits

'''
Given an array nums of integers, return how many of them contain 
an even number of digits.

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

'''
*/

int evenND(const vector<int> &nums){
    int c = 0;    
    string nn;
    for (auto n:nums){
        nn = to_string(n);
        if (nn.size() % 2 == 0){
            c++;
        }
    }
    return c;
}

int evenNDM(const vector<int> &nums){
    int c = 0;
    int x;
    int r;
    for (auto n:nums){
        x = 0;
        r = pow(10, x);
        //cout << n << "," << r << "," << n/r << endl;
        while (n/r != 0){
            r = pow(10, x);
            cout << n << "," << r << "," << n/r << endl;
            x++;
        }
        if(x%2 == 0){
            c++;
        }
    }
    return c;
}

int main(){
    vector<int> nums = {12,345,2,6,7896};
    
    //cout << evenND(nums) << endl;
    cout << evenNDM(nums);
    return 0;
}

