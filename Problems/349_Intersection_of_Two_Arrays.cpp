#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> intersectionTwoArrays(vector<int> nums1, vector<int> nums2){
    vector<int> inter;
    set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(inter));
    return inter;
}

int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2, 2};
    vector<int> result;
    result = intersectionTwoArrays(nums1, nums2);
    for (auto r:result){
        cout << r << " ";
    }
    cout << endl;

    nums1 = {4,9,5};
    nums2 = {9,4,9,8,4};
    result = intersectionTwoArrays(nums1, nums2);
    for (auto r:result){
        cout << r << " ";
    }

    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./349_Intersection_of_Two_Arrays 
2 2 
9
*/