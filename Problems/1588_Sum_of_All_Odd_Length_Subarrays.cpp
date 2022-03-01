#include <iostream>
#include <vector>
using namespace std;

/*
# 1588. Sum of All Odd Length Subarrays
#----------------------------------------
'''
Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.
'''
*/

int sumOddLenArr(vector<int> arr){
    int ans = 0;
    vector<int> subarr;
    cout << "arr.size()" << arr.size() << endl;
    for (int window=1; window < arr.size()+1; window+=2){
        for (int i=0; i < arr.size() - window+1; i++){
            subarr = {arr.begin()+i, arr.begin()+window+i};
            cout << "i=" << i << " ,window=" << window;

            for (auto a:subarr){
                cout << "[" << a;
                ans += a;
            }
            cout << "]" << endl;
        }
        
    }
    return ans;
}


int sum2(vector<int> arr){
    int ans = 0;
    int n = arr.size();
    for (int start=0; start<n; start++){
        int sub_sum = 0;
        for (int i=start; i<n; i++){
            sub_sum += arr[i];
            if ((i-start)%2 == 0){
                ans += sub_sum;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr = {1,4,2,5,3};
    cout << sumOddLenArr(arr);
    cout << sum2(arr);
    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./1588_Sum_of_All_Odd_Length_Subarrays 
arr.size()5
i=0 ,window=1[1]
i=1 ,window=1[4]
i=2 ,window=1[2]
i=3 ,window=1[5]
i=4 ,window=1[3]
i=0 ,window=3[1[4[2]
i=1 ,window=3[4[2[5]
i=2 ,window=3[2[5[3]
i=0 ,window=5[1[4[2[5[3]
58
*/