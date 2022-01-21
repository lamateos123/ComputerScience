#include<iostream>
#include<vector>
#include<string> 
#include<cmath>
#include<algorithm>

using namespace std;

/*

# 7. Reverse Integer
# ---------------------------------------------------------
# Given a signed 32-bit integer x, return x with its digits reversed. 
# If reversing x causes the value to go outside the signed 32-bit integer range then zero
#----------------------------------------------------------
# example 1
# Input: x = 123
# Output: 321
# Example 2:
# Input: x = -123
# Output: -321
# Example 3:
# Input: x = 120
# Output: 21

*/


int reverse_int(int x){
    string s = to_string(abs(x));
    reverse(s.begin(), s.end());
    if (x < 0) 
        s = "-" + s;
    if (x > 2147483647 or x < -2147483648)
        return 0;
    return stoi(s);

}

int main(){
    int x;
    x = 123;
    cout << reverse_int(x) << endl;
    x = -123;
    cout << reverse_int(x) << endl;
    x = 120;
    cout << reverse_int(x) << endl;
}

/*

~/Desktop/ComputerScience/Problems$ ./7_Reverse_Integer 
321
-321
21

*/