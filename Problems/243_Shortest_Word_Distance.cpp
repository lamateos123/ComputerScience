#include<iostream>
#include<vector>

using namespace std;

/*
# 243. Shortest Word Distance
'''
Given an array of strings wordsDict and two different strings that already exist in 
the array word1 and word2, return the shortest distance between these two words in the list.

 

Example 1:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], 
word1 = "coding", word2 = "practice"
Output: 3

'''
*/

int shortestWD(vector<string> wordsDict, string word1, string word2){
        int mind = wordsDict.size();
        int i1=-1;
        int i2=-1;
        for(int i =0;i<wordsDict.size();i++)
        {
            if(wordsDict[i]==word1)
                i1=i;
            else if(wordsDict[i]==word2)
                i2=i;
            if(i1!= -1 && i2!=-1)
            {
                mind = min(mind,abs(i2-i1));
            }
            
        }
        return mind;
}    

int shortestWD2(vector<string> wordsDict, string word1, string word2){
        int mind = wordsDict.size();
        int i1=-1;
        int i2=-1;
        for(int i =0;i<mind;i++)
        {
            if(wordsDict[i]==word1)
                i1=i;
            else if(wordsDict[i]==word2)
                i2=i;
            if(i1!= -1 && i2!=-1)
            {
                mind = min(mind,abs(i2-i1));
            }
            
        }
        return mind;
}

int main() {
    vector<string> wordsDict;
    string word1;
    string word2;
    //wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
    //word1 = "coding";
    //word2 = "practice";
    wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
    word1 = "makes";
    word2 = "coding";

    cout << shortestWD(wordsDict, word1, word2) << endl;;
    cout << shortestWD2(wordsDict, word1, word2) << endl;;
    return 0;
}