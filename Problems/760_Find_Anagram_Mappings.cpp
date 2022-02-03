#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
You are given two integer arrays nums1 and nums2 where nums2 is an anagram of nums1. 
Both arrays may contain duplicates.

Return an index mapping array mapping from nums1 to nums2 where mapping[i] = j means 
the ith element in nums1 appears in nums2 at index j. If there are multiple answers, 
return any of them.

An array a is an anagram of an array b means b is made by randomizing the order of 
the elements in a.

Example 1:

Input: nums1 = [12,28,46,32,50], nums2 = [50,12,32,46,28]
Output: [1,4,3,2,0]
Explanation: As mapping[0] = 1 because the 0th element of nums1 appears at nums2[1], 
and mapping[1] = 4 because the 1st element of nums1 appears at nums2[4], and so on.

Example 2:

Input: nums1 = [84,46], nums2 = [84,46]
Output: [0,1]
*/
int getIndex(vector<int> v, int k){
    auto it = find(v.begin(), v.end(), k);
    if (it != v.end()){ 
        int index = it -v.begin();
        return index;
    } else {
        return -1;
    }
}

vector<int> anaMap(vector<int> nums1, vector<int> nums2){
    vector<int> ans;
    for (auto n:nums1){
        //cout << getIndex(nums2,n)<< ",";
        ans.push_back(getIndex(nums2,n));
    }
    return ans;
}

int main(){
    vector<int> nums1 = {12,28,46,32,50};
    vector<int> nums2 = {50,12,32,46,28};
    vector<int> ans = anaMap(nums1, nums2);
    for (auto a:ans){
        cout << a << " ";
    }
    return 0;
}
/*
~/github/ComputerScience/Problems$ ./ 60_Find_Anagram_Mappings 
1 4 3 2 0 
*/