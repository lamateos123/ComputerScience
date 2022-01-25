#include<iostream>
#include<vector>
using namespace std;

/*
# 2011 Final Value of Variable After Performing Operations
#--------------------------------------------------------
#There is a programming language with only four operations and one 
#variable X:
#
#    ++X and X++ increments the value of the variable X by 1.
#    --X and X-- decrements the value of the variable X by 1.
#
#Initially, the value of X is 0.
#
#Given an array of strings operations containing a list of operations, 
#return the final value of X after performing all the operations.

#Example 1:
#Input: operations = ["--X","X++","X++"]
#Output: 1
#Explanation: The operations are performed as follows:
#Initially, X = 0.
#--X: X is decremented by 1, X =  0 - 1 = -1.
#X++: X is incremented by 1, X = -1 + 1 =  0.
#X++: X is incremented by 1, X =  0 + 1 =  1.
*/

int finalValue(vector<string> operations){
    int result = 0;
    for (auto s:operations){
        if (s == "X++" or s == "++X"){
            result++;
        } else {
            result--;
        }
    }
    return result;
}

int main(){
    vector<string> operations = {"--X","X++","X++"};
    cout << finalValue(operations) << endl;
    operations = {"++X","++X","X++"};
    cout << finalValue(operations) << endl;
    operations = {"X++","++X","--X","X--"};
    cout << finalValue(operations) << endl;

    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./2011_Final_Value_of_Variable_After_Performing_Operations 
1
3
0
*/