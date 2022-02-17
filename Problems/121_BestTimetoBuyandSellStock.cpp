#include<iostream>
#include<vector>

using namespace std;

/*
# 121. Best Time to Buy and Sell Stock
'''
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

'''
*/

int sellBuy(const vector<int> &prices){
    int minp = 999999;
    int maxp = 0;
    for (int i=0; i<prices.size(); i++){
        if (prices[i] < minp){
            minp = prices[i];
        } else if ((prices[i]-minp) > maxp) {
            maxp = prices[i]-minp;
        }
    }
    return maxp;
}

int sellBuyBruteForce(const vector<int> &prices){
    int p = 0;
    for (int i=0; i<prices.size()-1; i++){
        for (int j=i+1; j<prices.size(); j++){
            if(prices[j]-prices[i] > p){
                p = prices[j]-prices[i];
            }
        }
    }
    return p;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    //prices = {7,6,4,3,1};
    prices = {1,2,4};
    cout << sellBuyBruteForce(prices);
    //cout << sellBuy(prices);
    return 0;
}