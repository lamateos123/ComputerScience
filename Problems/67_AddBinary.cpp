#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/*
# 67. Add Binary
'''
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
'''
*/

string addBinary(string a, string b){
    string ans = "";
    string temp;
    string r;
    char x;
    char y;
    char carry = '0';
    int total;

    // fill with zeros the smallest string to have both same size
    if (a.size() >= b.size()) {
        total = a.size();
        temp = string((total - b.size()),'0');
        b = temp + b;
    } else {
        total = b.size();
        temp = string((total - a.size()),'0');
        a = temp + a;
    } 

    //cout << a << endl;
    //cout << b << endl;
    //cout << total << endl;

    // perform the sum
    for (int i=total-1; i >= 0; i--){
        //cout << i << endl;
        x = a[i];
        y = b[i];
        //cout << x << y <<endl;
        if (x == '0' and y == '0' and carry == '0') {
            r = "0";
            carry = '0';
        }
        if (x == '0' and y == '0' and carry == '1') {
            r = "1";
            carry = '0';
        }
        if (x == '0' and y == '1' and carry == '0') {
            r = "1";
            carry = '0';
        }
        if (x == '0' and y == '1' and carry == '1') {
            r = "0";
            carry = '1';
        }
        if (x == '1' and y == '0' and carry == '0') {
            r = "1";
            carry = '0';
        }
        if (x == '1' and y == '0' and carry == '1') {
            r = "0";
            carry = '1';
        }
        if (x == '1' and y == '1' and carry == '0') {
            r = "0";
            carry = '1';
        }
        if (x == '1' and y == '1' and carry == '1') {
            r = "1";
            carry = '1';
        }

    ans = ans + r;
    //cout << "ans=" << ans << "r" << r<< endl;

    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string a = "100";
    string b = "110010";
    cout << addBinary(a,b);
    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./67_AddBinary 
110110
*/