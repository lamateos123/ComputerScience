#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

*/
int twoSum(vector<int> nums, int k){
    int suma = -1;
    sort(nums.begin(),nums.end());
    if ((nums.size() < 2) or (nums[0]+nums[1]) > k) return -1;

    int maxi = nums[0]+nums[1];
    
    for (int i=0; i<nums.size(); i++){
        for (int j=0; j<nums.size(); j++){
            if (i!=j){
                suma = nums[i]+nums[j];
                if ((suma < k) and (suma > maxi)){
                    maxi=suma;
                }
            }
        }
    }
    return maxi;
}


int twoSumPointers(vector<int> nums, int k){    
    int ans = -1;
    int suma = -1;
    int l = 0;
    int r = nums.size()-1;
    sort(nums.begin(), nums.end());
    while(l<r){   
        suma = nums[l] + nums[r]     ;
        if (suma < k){
            ans = max(ans,suma);
            l += 1;
        } else {
            r -= 1;
        }
    }
    return ans;
}



int main(){
    vector<int> nums;
    int k;

    nums = {10,20,30};
    k = 15;
    cout << twoSum(nums,k) << endl;

    nums = {254,914,110,900,147,441,209,122,571,942,136,350,160,127,178,839,201,386,462,45,735,467,153,415,875,282,204,534,639,994,284,320,865,468,1,838,275,370,295,574,309,268,415,385,786,62,359,78,854,944};
    k = 200;
    cout << twoSum(nums,k) << endl;

    nums = {10,20,30};
    k = 15;
    cout << twoSumPointers(nums,k) << endl;

    nums = {254,914,110,900,147,441,209,122,571,942,136,350,160,127,178,839,201,386,462,45,735,467,153,415,875,282,204,534,639,994,284,320,865,468,1,838,275,370,295,574,309,268,415,385,786,62,359,78,854,944};
    k = 200;
    cout << twoSumPointers(nums,k) << endl;

    return 0;
}