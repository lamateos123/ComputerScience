#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

/*
# 1085. Sum of Digits in the Minimum Number
'''
Given an integer array nums, return 0 if the sum of the digits of the 
minimum integer in nums is odd, or 1 otherwise.

Example 1:

Input: nums = [34,23,1,24,75,33,54,8]
Output: 0
Explanation: The minimal element is 1, and the sum of those digits 
is 1 which is odd, so the answer is 0.

Example 2:

Input: nums = [99,77,33,66,55]
Output: 1
Explanation: The minimal element is 33, and the sum of those digits 
is 3 + 3 = 6 which is even, so the answer is 1.

'''
*/

bool dminN(vector<int> nums){
    //float mini = INFINITY;
    int mini = 9999999;
    int ans = 0;
    // get minimal element
    for (auto n:nums){
        if (mini > n) mini=n;
    }
    //cout << "mini=" << mini << endl;
    // add digits
    string minis = to_string(mini);
    //cout << "minis" << minis << endl;
    for (auto s:minis) 
    {
        ans += (int(s)-'0');
        //cout << int(s) << endl;
    }
    //cout << ans << endl;
    if (ans % 2 == 0) return 1;
    return 0;
}

bool dminN2(vector<int> nums){
    //float mini = INFINITY;
    int mini = 9999999;
    int ans = 0;
    int d = 0;
    // get minimal element
    for (auto n:nums){
        if (mini > n) mini=n;
    }
    //cout << "mini=" << mini << endl;
    // add digits
    while (mini != 0){
        d = mini%10;
        mini = mini/10 - d/10;
        //cout << "d=" << d << endl;
        ans += d;
    }
    if (ans % 2 == 0) return 1;
    return 0;
}

int main(){
    vector<int> nums;
    nums = {34,23,1,24,75,33,54,8};
    nums = {99,77,33,66,55};
    cout << dminN2(nums);
    return 0;
}
/*
~/github/ComputerScience/Problems$ ./1085_SumofDigitsintheMinimumNumber 
1
*/