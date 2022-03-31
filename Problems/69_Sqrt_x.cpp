#include<iostream>
using namespace std;

/*
# 69. Sqrt(x)
'''
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, 
and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, 
such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is 
truncated, 2 is returned.
'''
*/

int mySqrt(int x){
    int l = 0;
    int r = x;
    long long int mid;
    while (l <= r){
        mid = l + (r-l) / 2;
        if (x == mid*mid){
            return mid;
        }
        if (x > mid*mid){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main(){
    int x;
    x = 4;
    cout << mySqrt(x) << endl;

    x = 8;
    cout << mySqrt(x) << endl;
    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./69_Sqrt_x 
2
2
*/