#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
# 506. Relative Ranks
'''
You are given an integer array score of size n, where score[i] is the score of the 
ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the 
highest score, the 2nd place athlete has the 2nd highest score, and so on. 
The placement of each athlete determines their rank:

    The 1st place athlete's rank is "Gold Medal".
    The 2nd place athlete's rank is "Silver Medal".
    The 3rd place athlete's rank is "Bronze Medal".
    For the 4th place to the nth place athlete, their rank is their placement 
    number (i.e., the xth place athlete's rank is "x").

Return an array answer of size n where answer[i] is the rank of the ith athlete.

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

'''
*/

int getIndex(vector<int> v, int val){
    int index = -1;
    auto it = find(v.begin(), v.end(), val);
    if (it !=v.end()){
        index = it - v.begin();
    } else {
        index = -1;
    }
    return index;
}

vector<string> relativity(vector<int> score){
    vector<string> ans;
    int rank = -1;
    vector<int> temp = score;
    sort(temp.begin(),temp.end(),greater<int>());
    cout << endl;
    for (auto x:temp){
        cout << x << ", ";
    }
    cout << endl;
    for (int i=0; i<score.size(); i++){
        rank = getIndex(temp, score[i]);
        cout << "index:" << rank << "Value:" << temp[i] << endl;
        if (rank == 0) ans.push_back("Gold Medal");
        else if (rank == 1) ans.push_back("Silver Medal");
        else if (rank == 2) ans.push_back("Bronze Medal");
        else ans.push_back(to_string(rank+1));
    }
    return ans;
}

int main(){
    vector<int> score;
    score = {10,3,8,9,4};
    vector<string> ans;
    ans = relativity(score);
    for (auto i:ans){
        cout << i << ", ";
    }
    return 0;
}