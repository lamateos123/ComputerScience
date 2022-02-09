#include<iostream>
#include<vector>
#include<tuple>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

/*
# 1. Add two numbers
#-------------------------------------------------------------------
#Given an array of integers nums and an integer target, 
#return indices of the two numbers such that they add up to target.

#You may assume that each input would have exactly one solution, 
#and you may not use the same element twice.

#You can return the answer in any order.
#-------------------------------------------------------------------

# example 1
#----------
# Input: nums = [1,3,5,2,7,11,15], target = 10
# Output: [1,4]
# Output: Because nums[1] + nums[4] == 10, we return [1, 4].
#example 2
#---------
# Input: nums = [3,2,4,1], target = 7
# Output: [0,2]
*/

tuple<int, int> addTwo(vector<int> nums, int target){
    tuple<int, int> ans = {0,0};
    for (int i=0; i<nums.size(); i++){
        for (int j=1; j<nums.size(); j++){
            //cout << nums[i] << "'" << nums[j] << endl;
            if(target == nums[i]+nums[j]){   
                get<0>(ans) = i;
                get<1>(ans) = j;
                //return tuple<int, int>{i,j};
            }
        }
    }
    return ans;
}

tuple<int, int> addTwoRandom(vector<int> nums, int target){
    int a = 0;
    int b = 1;
    while (target != nums[a]+nums[b]){
        a = rand() % nums.size();
        b = rand() % nums.size();
        while (a == b){
            b = rand() % nums.size();
        }
    }
    return make_tuple(a,b);
}

tuple<int, int> addTwoUMap(vector<int> nums, int target){
    unordered_map<int, int> u;
    tuple<int, int> ans {0,0};
    int complement;
    for (int i=0; i<nums.size(); i++){
        complement = target - nums[i];
        //cout << "i = " << i << "  u[i] = " << u[i] << "  nums[i] = " << nums[i] <<"  complement = " << complement << endl;
        /*
        for (auto& x: u) {
            cout << x.first << ": " << x.second << endl;
        }
        */
        unordered_map<int,int>::const_iterator got = u.find (complement);

        // To retrieve the VALUE
        if (got == u.end()){
            u[nums[i]] = i;
            cout << "Not found" << endl;
        } else {
            //cout << "got->first = " << got->first << "  got->second" << got->second << endl;
            cout << "got->first = " << got->first << "  nums[i]" << nums[i] << endl;
            return make_tuple(got->first, nums[i]);
        }

        // Just to check if KEY found
        /*
        if (u.find(complement) == u.end()){
            cout << "Not found" << endl;
        } else {
            cout << "found" << endl;
        }
        */
    }
}

tuple<int, int> addTwoMap(vector<int> nums, int target){
    map<int, int> m;
    int complement;
    for (int i=0; i<nums.size(); i++){
        complement = target - nums[i];
        if (m.find(complement) != m.end()){
            return make_tuple(m.find(complement)->second, i);
        }
        m[nums[i]] = i;
    }
}


tuple<int, int> addTwo2pointers(vector<int> nums, int target){
    int front = 0;
    int rear = nums.size()-1;
    int sum;
    sort(nums.begin(), nums.end());
    while (front < rear) {
        sum = nums[front] + nums[rear];
        if (sum == target){
            return make_tuple(nums[front], nums[rear]);            
        } else if (sum < target) {
            front++;
        } else {
            rear++;       
        }
    }
}

int main(){
    vector<int> nums;
    tuple<int,int> ans;
    int target;
/*
    nums = {1,3,5,2,7,11,15};
    target = 10;
    ans = addTwo(nums, target);

    for (auto a:ans){
        cout << a << ", ";
    }
*/
    nums = {3,2,4,1};
    target = 7;
    ans = addTwoMap(nums, target);

    cout << get<0>(ans) << ", " << get<1>(ans) << endl;;
    


    return 0;
}