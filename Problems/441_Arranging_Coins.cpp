#include<iostream>
#include<math.h>
using namespace std;

/*
# 441. Arranging Coins
'''
You have n coins and you want to build a staircase with these coins. 
The staircase consists of k rows where the ith row has exactly i coins. 
The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

 

Example 1:

Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.

Example 2:

Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.

find the maximum k such that 
k(k+1) / 2 <= N

'''
*/

int arrangingCoins(int n){
    int l = 0;
    int r = n;
    int k;
    int cur;
    while (l<=r){
        k = l + (r-l) / 2; //(r+l)/2
        long cur = (long) k* (k+1) / 2;
        if (cur == n) {
            return k;
        }
        if (n < cur){
            r = k - 1;
        } else {
            l = k + 1;
        }
    }
    return r;
}

int arrangingCoinsFormula(int n){
    return sqrt((long)2 * n + 0.25) - 0.5;
}

int main(){
    int n = 8;
    cout << "rows=" << arrangingCoins(n) << endl;
    cout << "rows=" << arrangingCoinsFormula(n) << endl;
    return 0;
}