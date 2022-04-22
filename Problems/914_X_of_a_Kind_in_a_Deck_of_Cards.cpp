#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
# 914. X of a Kind in a Deck of Cards
'''
n a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible 
to split the entire deck into 1 or more groups of cards, where:

    Each group has exactly X cards.
    All the cards in each group have the same integer.

 

Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].

Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
'''
*/

int gcd(int a, int b){
    while ((a!=0 and b!=0) and a!=b){
        if (a>b) a%=b;
        else b%=a;
    }
    if (a>b) return a;
    else return b;
}

bool xKind(vector<int> deck){
    unordered_map<int,int> d;
    for(int i=0; i<deck.size(); i++){
        d[deck[i]] += 1;
    }
    cout << endl;
    for(auto x:d){
        cout << x.first << " / " << x.second << endl;
    }

    int xgcd = 0;
    for(auto x:d){
        xgcd = gcd(xgcd,x.second);
    }
    return xgcd > 1;
    //int mini = min(d.s ->second.begin(), d->second.end());
}

int main(){
    vector<int> deck;
    deck = {1,1,1,1,2,2,2,2,2,2};
    cout << boolalpha << xKind(deck);
    return 0;
}