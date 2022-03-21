#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
# 1287. Element Appearing More Than 25% In Sorted Array
#-------------------------------------------------------
'''
Given an integer array sorted in non-decreasing order, 
there is exactly one 
integer in the array that occurs more than 25% of the time, 
return that integer.

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Example 2:

Input: arr = [1,1]
Output: 1
'''
*/

int twentyFive(vector<int> arr){
    unordered_map<int,int> umap;
    for (auto i:arr){
        umap[i] += 1;
        if (umap[i] > arr.size()/4){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr;
    arr ={1,2,2,6,6,6,6,7,10};
    cout << twentyFive(arr);

    return 0;
}
/*
~/github/ComputerScience/Problems$ ./1287_Element_Appearing_More_Than_25p_In_Sorted_Array 
6
*/