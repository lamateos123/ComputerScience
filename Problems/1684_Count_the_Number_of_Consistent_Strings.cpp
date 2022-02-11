#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

/*
You are given a string allowed consisting of distinct characters and an 
array of strings words. 
A string is consistent if all characters in the string appear in the 
string allowed.

Return the number of consistent strings in the array words.

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only 
contain characters 'a' and 'b'.

Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.

*/

int countConsistent(const string &allowed, const vector<string> &words){
    int c = 0;
    string ss = "";

    for (auto word:words){
        cout << word << endl;
        set <char> s;
        vector<char> v;
        for (auto w:word){
            s.insert(w);            
        }
        //for (auto c:s){
        //    cout << c << endl;
        //}
        ss = {s.begin(),s.end()};
        //cout << ss << endl;

        int temp = 0;
        for (auto x:ss){
            auto it = find(allowed.begin(), allowed.end(), x);
            //cout << x << "->" << allowed << endl;
            if (it != allowed.end()) {
                temp += 1;
                //cout << "Here" << endl;
                //cout << endl;
            }
        }
        //cout << "temp=" << temp << "  ss size=" <<ss.size() << endl;
        if (temp == ss.size()){
            c += 1;
        }
    }
    return c;
}
/*
int countConsistentSet(const string &allowed, vector<string> &words){
    vector<int> v(words.size());

    vector<string>::iterator it;

    it = set_intersection (words.begin(), words.end(), allowed, allowed, v);
    v.resize(it-v.begin());
    return v.size();
}
*/

int main (){
    string allowed;
    vector<string> words;

    allowed = "ab"; 
    words = {"ad","bd","aaab","baa","badab"};
    allowed = "abc";
    words = {"a","b","c","ab","ac","bc","abc"};

    cout << countConsistent(allowed, words);

    return 0;
}

/*
~/github/ComputerScience/Problems$ ./1684_Count_the_Number_of_Consistent_Strings 
a
b
c
ab
ac
bc
abc
7
*/