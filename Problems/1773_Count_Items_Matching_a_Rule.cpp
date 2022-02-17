#include<iostream>
#include<vector>

using namespace std;

/*
# 1773. Count Items Matching a Rule
#-------------------------------------
'''
You are given an array items, where each 
items[i] = [typei, colori, namei] describes the type, color, 
and name of the ith item. You are also given a rule represented 
by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

    ruleKey == "type" and ruleValue == typei.
    ruleKey == "color" and ruleValue == colori.
    ruleKey == "name" and ruleValue == namei.

Return the number of items that match the given rule.
'''
*/
int countItems(const vector<vector<string>> &items, string ruleKey, string ruleValue){
    int c = 0;
    int ruleIndex = 0;
    if (ruleKey == "color") ruleIndex = 1;
    else if (ruleKey == "type") ruleIndex = 0;
    else ruleIndex = 2;

    for (auto item:items){
        if (item[ruleIndex] == ruleValue) c+=1;
    }
    return c;
}

int main(){
    vector<vector<string>> items = {{"phone","blue","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}};
    string ruleKey = "color";
    string ruleValue = "silver";
    cout << countItems(items, ruleKey, ruleValue);
    return 0;
}