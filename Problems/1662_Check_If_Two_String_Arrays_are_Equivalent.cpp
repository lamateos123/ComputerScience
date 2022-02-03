#include<iostream>
#include<vector>

using namespace std;

/*
Given two string arrays word1 and word2, return true if the two arrays represent 
the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order 
forms the string.

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.

Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
*/

bool twoStrings(vector<string> word1, vector<string> word2){
    string s1 = "";
    string s2 = "";
    for(auto w:word1){
        s1+=w;
    }
    for(auto w:word2){
        s2+=w;
    }
    if (s1==s2) return true;
    return false;
}

void join(vector<string>& ss, string& s){
    s.clear();

    for (vector<string>::const_iterator p = ss.begin(); p!=ss.end(); p++){
        s+=*p;
    }
}

bool twoStrings_B(vector<string> word1, vector<string>word2){
    string s1 = "";
    join(word1, s1);
    string s2 = "";
    join(word2, s2);
    if (s1==s2) return true;
    return false;
}

int main(){
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};
    cout << boolalpha << twoStrings_B(word1, word2);
    return 0;
}
/*
~/github/ComputerScience/Problems$ ./1662_Check_If_Two_StrArrays_are_Equivalent 
true
*/