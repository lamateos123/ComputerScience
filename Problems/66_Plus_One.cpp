#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
# 66. Plus One
'''
You are given a large integer represented as an integer array digits, where each 
digits[i] is the ith digit of the integer. The digits are ordered from most 
significant to least significant in left-to-right order. The large integer 
does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
'''
*/
/*
vector<int> plusOne(vector<int> digits){
    vector<int> ans = {};
    int num = 0;
    int m = 1;
    reverse(digits.begin(), digits.end());
    for (auto d:digits){
        num += d * m;
        m *= 10;
    }
    num += 1;
    string nums = to_string(num);
    for (auto n:nums){
        ans.push_back(n-'0');
    }
    return ans;
}
*/
vector<int> plusOne(vector<int> digits){
    for (int i=digits.size()-1; i>=0; i--){
        cout << "here";
        if(digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i]++;
            return digits;
        }
    }

    digits[0] = 1;
    digits.push_back(0);
    return digits;
}

int main(){
    vector<int> digits = {4,3,2,1};
    digits = {9,8,7,6,5,4,3,2,1,9};
    digits = {9};

    vector<int> ans;
    ans = plusOne(digits);
    for (auto a:ans){
        cout << a<< ",";
    }
    return 0;
}