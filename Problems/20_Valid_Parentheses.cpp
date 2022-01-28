#include<iostream>
#include<vector>
#include<strstream>
using namespace std;

/*
# 20. Valid Parentheses
#-------------------------------------------------------------------
# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
# determine if the input string is valid.
# An input string is valid if:
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Examples:
# Input: s = "()"
# Output: true
# Input: s = "()[]{}"
# Output: true
# Input: s = "(]"
# Output: false
# Input: s = "([)]"
# Output: false
*/

bool validParentheses(string s){
    vector<char> stack;
    for (auto c:s){
        //cout << c << endl;
        if (c == '(' || c == '[' || c == '{' ){
            stack.push_back(c);
            cout << c;
        } else if (stack.size() > 0){
            char temp = stack[stack.size()-1];
            if (c == ')' && temp =='(') {
                stack.pop_back();
                cout << c;
            }
            else if (c == ']' && temp =='[') {
                stack.pop_back();
                cout << c;
            }
            else if (c == '}' && temp =='{') {
                stack.pop_back();
                cout << c;
            } else {
                return false;
            }   
        }
    }
    return true;
}

int main(){
    string s;

    s = "()";
    cout << boolalpha << validParentheses(s) << endl;

    s = "()[]{}";
    cout << boolalpha << validParentheses(s) << endl;

    s = "(]";
    cout << boolalpha << validParentheses(s) << endl;

    s = "([)]";
    cout << boolalpha << validParentheses(s) << endl;

    return 0;
}
/*
~/github/ComputerScience/Problems$ ./20_Valid_Parentheses 
()true
()[]{}true
(false
([false
*/