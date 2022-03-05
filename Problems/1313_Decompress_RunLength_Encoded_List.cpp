#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
# 1287. Element Appearing More Than 25% In Sorted Array
#-------------------------------------------------------
'''
Given an integer array sorted in non-decreasing order, there is exactly one 
integer in the array that occurs more than 25% of the time, return that integer.


Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Example 2:

Input: arr = [1,1]
Output: 1

'''
*/

int twentyfive(vector<int> arr){
    unordered_map<int,int> umap;
    for (auto a:arr){
        umap[a] += 1;
        if (umap[a] > arr.size()/4){
            return a;
        }
    }
    return 0;
}

int main() {
    vector<int> arr = {1,2,2,6,6,6,6,7,10};
    cout << twentyfive(arr);
    return 0;
}
/*
~/github/ComputerScience/Problems$ ./1313_Decompress_RunLength_Encoded_List 
6
*/