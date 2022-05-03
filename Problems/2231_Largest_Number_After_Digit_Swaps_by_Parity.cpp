#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*# 2231. Largest Number After Digit Swaps by Parity
'''
You are given a positive integer num. You may swap any two digits of num that have 
the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.

 

Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is 
the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of 
different parities.
'''
*/

int largestNumberADSP(int num){
    vector<int> nums;
    vector<int> nums_even;
    vector<int> nums_odd;
    string temp = "";
    string num_str = to_string(num);
    
    for(auto i:num_str){
        int j = i-'0';
        if (j%2==0) nums_even.push_back(j);
        else nums_odd.push_back(j);
    }
    sort(nums_even.begin(),nums_even.end(), greater<int>());
    sort(nums_odd.begin(),nums_odd.end(), greater<int>());

    int m = 0;
    int n = 0;

    for (auto i:num_str){
        int j = i-'0';
        if (j%2==0){
            nums.push_back(nums_even[m]);
            m+=1;
        } else {
            nums.push_back(nums_odd[n]);
            n+=1;
        }
    }

    for (auto i:nums) {
        //num_str = to_str(i);
        temp+=to_string(i);
    }

    //cout <<"HERE:" << temp << endl;
    return stoi(temp);
}

int main(){
    int num;
    num = 1234;
    cout << largestNumberADSP(num);
    return 0;
}