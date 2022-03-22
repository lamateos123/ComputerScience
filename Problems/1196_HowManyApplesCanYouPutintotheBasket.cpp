
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
# 1196. How Many Apples Can You Put into the Basket
'''
You have some apples and a basket that can carry up to 5000 units of weight.

Given an integer array weight where weight[i] is the weight of the ith apple, 
return the maximum number of apples you can put in the basket.

 

Example 1:

Input: weight = [100,200,150,1000]
Output: 4
Explanation: All 4 apples can be carried by the basket since their sum of weights is 1450.

Example 2:

Input: weight = [900,950,800,1000,700,800]
Output: 5
Explanation: The sum of weights of the 6 apples exceeds 5000 so we choose any 5 of them.

'''
*/

int manyApples(vector<int> weight){
    int c = 0;
    int temp = 0;
    int limit = 5000;
    sort(weight.begin(), weight.end());
    for (auto w:weight){
        if (temp+w <= limit){
            temp += w;
            c += 1;
        } else {
            return c;
        }
    }
    return c;
}

int main(){
    vector<int> weight = {100,200,150,1000};
    cout << manyApples(weight);
    return 0;
}