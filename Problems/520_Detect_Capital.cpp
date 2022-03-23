#include<iostream>
#include<cctype>

using namespace std;

/*
We define the usage of capitals in a word to be right when one 
of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is 
right.

Example 1:

Input: word = "USA"
Output: true

Example 2:

Input: word = "FlaG"
Output: false
*/

bool detectCapital(string word){
    int cl = 0;
    int cu = 0;
    int c_start = 0;
    for (auto i:word){        
        cout << i << endl;
        if (islower(i)) cl += 1;
        else if (isupper(i)) cu += 1;
    }
    if ((isupper(word[0])) && (word.size() - cl == 1)){
        return true;
    }
    if (cl == word.size()) return true;
    if (cu == word.size()) return true;
    return false;
}

int main(){
    string word;
    word = "USA";
    cout << boolalpha << detectCapital(word) << endl;
    word = "here";
    cout << boolalpha << detectCapital(word) << endl;
    word = "FlaG";
    cout << boolalpha << detectCapital(word) << endl;
    return 0;
}