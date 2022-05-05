#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
# 989. Add to Array-Form of Integer
'''
The array-form of an integer num is an array representing its digits in left to right order.

    For example, for num = 1321, the array form is [1,3,2,1].

Given num, the array-form of an integer, and an integer k, return the array-form of the 
integer num + k.


Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
'''
*/

vector<int> addAFI(vector<int> num, int k){
    int n = num.size();
    int carry = 0;
    vector<int> ans;

    for (int i=n-1; i>=0 || k!=0; i--){
        int digit = k%10;
        k = k/10;
        int sum = carry + digit;
        if(i>=0){
            sum+=num[i];
        }
        ans.push_back(sum%10);
        carry = sum/10;
    }
    if (carry) ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    return ans;

}

/*
vector<int> addAFI(vector<int> num, int k){
    vector<int> ans;
    string nums = "";
    int temp = 0;
    for(auto i:num) nums += to_string(i);
    temp = stoi(nums);
    temp+=k;
    nums = to_string(temp);
    for (auto i:nums) ans.push_back(i-'0');
    return ans;
}
*/

int main(){
    vector<int> ans;
    vector<int> num;
    int k;
    num = {1,2,0,0};
    k = 34;
    ans = addAFI(num,k);
    cout << endl;
    for (auto i:ans){
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}