#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
//#include<boost/algorithm/string.hpp>
using namespace std;

/*
# 2129. Capitalize the Title
'''
You are given a string title consisting of one or more words 
separated by a single space, where each word consists of English 
letters. Capitalize the string by changing the capitalization of 
each word such that:

    If the length of the word is 1 or 2 letters, change all 
    letters to lowercase.
    Otherwise, change the first letter to uppercase and the 
    remaining letters to lowercase.

Return the capitalized title.

 

Example 1:

Input: title = "capiTalIze tHe titLe"
Output: "Capitalize The Title"
Explanation:
Since all the words have a length of at least 3, the first 
letter of each word is uppercase, and the remaining letters 
are lowercase.

Example 2:

Input: title = "First leTTeR of EACH Word"
Output: "First Letter of Each Word"
Explanation:
The word "of" has length 2, so it is all lowercase.
The remaining words have a length of at least 3, so the 
first letter of each remaining word is uppercase, and the 
remaining letters are lowercase.

Example 3:

Input: title = "i lOve leetcode"
Output: "i Love Leetcode"
Explanation:
The word "i" has length 1, so it is lowercase.
The remaining words have a length of at least 3, so the 
first letter of each remaining word is uppercase, and the 
remaining letters are lowercase.
'''
*/
/*
string capTitle(string title){
    string ans = "";
    //string temp = title.substr(0, title.find(" "));
    //cout << temp << endl;

    stringstream ss(title);
    string word;
    while(ss >> word) {
        cout << word << ".." << endl;
        if (word.size() > 2){
            //boost::algorithm::to_upper(word);
            boost::algorithm::to_lower(word);
            word[0] = toupper(word[0]);
            ans += word + " ";
        } else {
            boost::algorithm::to_lower(word);
            ans += word + " ";
        }
    }
    cout << ans << "qqq" << endl;
    return ans.substr(0, ans.size()-1);
}
*/
string capTitleChar(string title){
    stringstream ss(title);
    string word;
    string ans = "";
    while(ss >> word) {
        for (int i=0; i<word.size(); i++){
            word[i] = tolower(word[i]);
        }
        if (word.size() > 2){
            word[0] = toupper(word[0]);
        }
        ans += word + " ";
    }
    return ans.substr(0, ans.size()-1);
}

int main(){
    string title = "capiTalIze tHe titLe";
    cout << capTitleChar(title);
    return 0;
}