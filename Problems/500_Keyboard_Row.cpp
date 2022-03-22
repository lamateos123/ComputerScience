#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
# 500. Keyboard Row
'''
Given an array of strings words, return the words that can be typed using letters of 
the alphabet on only one row of American keyboard like the image below.

In the American keyboard:

    the first row consists of the characters "qwertyuiop",
    the second row consists of the characters "asdfghjkl", and
    the third row consists of the characters "zxcvbnm".

Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]

Example 2:

Input: words = ["omk"]
Output: []

Example 3:

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]

'''
*/
vector<string> keyRow(vector<string> words){
    vector<string> ans = {};
    string r1 = "qwertyuiopQWERTYUIOP";
    string r2 = "asdfghjklASDFGHJKL";
    string r3 = "zxcvbnmZXCVBNM";
    int c1 = 0; 
    int c2 = 0; 
    int c3 = 0;

    for (auto word:words){
        for (auto w:word){
            if (r1.find(w)!=string::npos) c1++;
            else if (r2.find(w)!=string::npos) c2++;
            else if (r3.find(w)!=string::npos) c3++;
        }
        if (c1 == word.size()) ans.push_back(word);
        else if (c2 == word.size()) ans.push_back(word);
        else if (c3 == word.size()) ans.push_back(word);
        c1 = 0;
        c2 = 0;
        c3 = 0;
    }
    return ans;
}
int main(){
    vector<string> words;
    vector<string> ans;
    words = {"Hello","Alaska","Dad","Peace"};
    ans = keyRow(words);
    for (auto word:ans){
        cout << word << ",";
    }
}
