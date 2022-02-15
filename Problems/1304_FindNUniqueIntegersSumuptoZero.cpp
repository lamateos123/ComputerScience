#include<iostream>
#include<vector>

using namespace std;

/*
# 1304. Find N Unique Integers Sum up to Zero
'''
Given an integer n, return any array containing n unique integers 
such that they add up to 0.

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

'''
*/
vector<int> ans;

vector<int> sumZero(int n){
    //vector<int> ans;
    if (n==1){
        ans.push_back(0);
    } else {
        if (n%2 != 0){
            ans.push_back(0);
        }
        for(int i=0; i<n/2; i++){
            ans.push_back(i+1);
            ans.push_back((i+1)*-1);
        }
    }


    return ans;
}

int main(){
    int n = 5;
    ans = sumZero(n);
    for (auto i:ans){
        cout << i << "," ;
    }
    return 0;
}
