#include<iostream>

using namespace std;

/*
# 1844. Replace All Digits with Characters
'''
You are given a 0-indexed string s that has lowercase English 
letters in its even indices and digits in its odd indices.

There is a function shift(c, x), where c is a character and x is 
a digit, that returns the xth character after c.

    For example, shift('a', 5) = 'f' and shift('x', 0) = 'x'.

For every odd index i, you want to replace the digit s[i] with 
shift(s[i-1], s[i]).

Return s after replacing all digits. It is guaranteed that 
shift(s[i-1], s[i]) will never exceed 'z'.

Example 1:

Input: s = "a1c1e1"
Output: "abcdef"
Explanation: The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('c',1) = 'd'
- s[5] -> shift('e',1) = 'f'

Example 2:

Input: s = "a1b2c3d4e"
Output: "abbdcfdhe"
Explanation: The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('b',2) = 'd'
- s[5] -> shift('c',3) = 'f'
- s[7] -> shift('d',4) = 'h'
'''

For, a + char(2) - '0' = a + 2 = c ('a' ASCII value is 97 then 97 + 2 = 99 
which is ASCII value of c and the conversion is done implicitly by the compiler)
so result is "ac"
*/

string replaceDigits(string s){
    for (int i=1; i<=s.size(); i+=2){
        //cout << s[i-1]-'0' <<','<<char(s[i-1]-'0');
        s[i]+=(s[i-1]-'0');        

        cout << s[i-1] << ",";
    }

    return s;
}

int main(){
    string s = "a1c1e1";
    cout << replaceDigits(s);
    return 0;
}