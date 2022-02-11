#include<iostream>
#include<vector>
using namespace std;

/*
# 1720. Decode XORed Array
#---------------------------
'''
There is a hidden integer array arr that consists of n non-negative integers.

It was encoded into another integer array encoded of length n - 1, 
such that encoded[i] = arr[i] XOR arr[i + 1]. 
For example, if arr = [1,0,2,1], then encoded = [1,2,3].

You are given the encoded array. You are also given an integer first, 
that is the first element of arr, i.e. arr[0].

Return the original array arr. It can be proved that the answer exists and is unique.

Example 1:

Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and 
encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]

Example 2:

Input: encoded = [6,2,7,3], first = 4
Output: [4,2,0,7,4]

'''
*/

vector<int> decodeXOR(vector<int> &encoded, int first){
    vector<int> ans = {first};
    int temp;
    for (auto x:encoded){
        temp = x^ans[ans.size()-1];
        ans.push_back(temp);
        //cout << x << ", " << ans[ans.size()-1] << ", " << temp << endl;
    }
    return ans;
}

int main(){
    vector<int> encoded = {6,2,7,3};
    int first = 4;
    vector<int> result = decodeXOR(encoded, first);
    for (auto r:result){
        cout << r << ",";
    }
    return 0;
}

/*
~/github/ComputerScience/Problems$ ./1720_Decode_XORed_Array 
4,2,0,7,4
*/



