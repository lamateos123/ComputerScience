#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*
# 387. First Unique Character in a String
'''
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1
*/
int firstUnique(string s){
    unordered_map<char,int> d;
    for (auto ch:s){
        d[ch]+=1;
    }

    int i = 0;
    for (auto ch:s){
        if (d[ch]==1){
            return i;
        }
        i+=1;
    }
    return -1;

}
/*
int firstUnique(string s){
    int i = 0;
    for (auto a:s){
        if (count(s.begin(), s.end(), a) == 1){
            return i;
        }
        i += 1;
    }
    return -1;
}
*/

int main(){
    string s = "";
    s = "leetcode";
    cout << firstUnique(s) << endl;
    s = "loveleetcode";
    cout << firstUnique(s) << endl;
    s = "aabb";
    cout << firstUnique(s) << endl;
    return 0;
}
