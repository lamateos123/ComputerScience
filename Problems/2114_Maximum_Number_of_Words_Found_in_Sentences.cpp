#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

/*
# 2114. Maximum Number of Words Found in Sentences
#-------------------------------------------------
#A sentence is a list of words that are separated by a single space 
#with no leading or trailing spaces.
#
#You are given an array of strings sentences, where each sentences[i] 
#represents a single sentence.
#
#Return the maximum number of words that appear in a single sentence.

#Example 1:

#Input: sentences = ["alice and bob love leetcode", "i think so too", 
#"this is great thanks very much"]
#Output: 6
#Explanation: 
#- The first sentence, "alice and bob love leetcode", has 5 words in total.
#- The second sentence, "i think so too", has 4 words in total.
#- The third sentence, "this is great thanks very much", has 6 words in total.
#Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.
*/

int maxNumWords(vector<string> sentences){
    int max_counter = 0;
    for (auto sentence:sentences){
        stringstream ss(sentence);
        string word;
        int word_counter = 0;
        while (ss >> word){
            //cout << word << endl;
            word_counter++;
        }
        if (word_counter > max_counter) max_counter = word_counter;
    }
    return max_counter;
}

int main(){
    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    cout << maxNumWords(sentences) << endl;

    sentences = {"please wait", "continue to fight", "continue to win"};
    cout << maxNumWords(sentences) << endl;

    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./2114_Maximum_Number_of_Words_Found_in_Sentences 
6
3
*/