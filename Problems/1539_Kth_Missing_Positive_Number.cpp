#include<iostream>
#include<vector>

using namespace std;

/*
# 1539. Kth Missing Positive Number
#------------------------------------

#Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
#Find the kth positive integer that is missing from this array.

#Example 1:
#Input: arr = [2,3,4,7,11], k = 5
#Output: 9
#Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. 
#The 5th missing positive integer is 9.

#Example 2:
#Input: arr = [1,2,3,4], k = 2
#Output: 6
#Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/

bool in(vector<int> arr, int v){
    for (auto e:arr){
        if (v == e) return true;
    }
    return false;
}

int kthMissing(vector<int> arr, int k){
    vector<int> missing;
    int counter = 0;
    for (int n=1; n<100000; n++){
        if (in(arr,n)){
            arr.erase(arr.begin());
        } else {
            missing.push_back(n);
            counter++;
            if (k == counter) return missing[counter-1];
        }
    }
    return 0;
}

int kthMissing_improved(vector<int> arr, int k){
    vector<int> missing;
    int counter = 0;
    int j = 0; // counter for passing the arr, instead of erasing first element
    for (int n=1; n < 100000; n++){
        if (in({arr.begin()+j, arr.end()},n)){
            j++;
        } else {
            missing.push_back(n);
            counter++;
            if (k==counter) return missing[counter-1];
        }
    }
    return 0;
}

int main(){
    vector<int> arr;

    arr = {2,3,4,7,11}; 
    int k = 5;
    cout << kthMissing(arr, k) << endl;


    arr = {1,2,3,4};
    k = 2;
    cout << kthMissing_improved(arr, k);
    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./1539_Kth_Missing_Positive_Number 
9
6
*/