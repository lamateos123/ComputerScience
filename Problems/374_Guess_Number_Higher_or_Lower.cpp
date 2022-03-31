#include<iostream>
using namespace std;

/*
# 374. Guess Number Higher or Lower
'''
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

    -1: Your guess is higher than the number I picked (i.e. num > pick).
    1: Your guess is lower than the number I picked (i.e. num < pick).
    0: your guess is equal to the number I picked (i.e. num == pick).

Return the number that I picked.

 

Example 1:

Input: n = 10, pick = 6
Output: 6

Example 2:

Input: n = 1, pick = 1
Output: 1

Example 3:

Input: n = 2, pick = 1
Output: 1
'''
*/

int pick;
int n;

int guess(int x){
    if (x == pick){
        return 0;
    }
    if (x < pick){
        return 1;
    } else {
        return -1;
    }
}

int guessNumber(int n){
    int l = 0;
    int r = n;
    int mid;
    while (l<=r){
        mid = l + (r-l)/2;
        if (guess(mid) == 0){
            return mid;
        }
        if (guess(mid) == 1){
            l = mid + 1;
        }
        if (guess(mid) == -1){
            r = mid - 1;
        }
    }
    return mid;
}

int main(){
    n = 10;
    pick = 6;
    cout << guessNumber(10);
    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./374_Guess_Number_Higher_or_Lower 
6
*/