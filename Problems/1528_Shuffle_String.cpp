#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
# 1528. Shuffle String
#---------------------
#You are given a string s and an integer array indices of the same length. 
#The string s will be shuffled such that the character at the ith position 
#moves to indices[i] in the shuffled string.

#Return the shuffled string.
*/
string shuffleString(string s, vector<int> indices){
    vector<char> c (s.size());
    int pointer = 0;
    for (auto index:indices){
        c[index] = s[pointer];
        pointer++;
    }
    string ss(c.begin(), c.end());
    return ss;
}

int main(){
    string s;
    vector<int> indices;
    string ans;

    s = "eycodm_";
    indices = {6,1,3,4,5,0,2};
    cout << shuffleString(s, indices);

    return 0;
}
/*
~/github/ComputerScience/Problems$ ./1528_Shuffle_String 
my_code
*/