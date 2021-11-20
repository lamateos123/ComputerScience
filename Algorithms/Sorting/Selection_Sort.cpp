#include<iostream>
#include<vector>

using namespace std;

vector<int> nums = {6,5,7,4,8,3,1,9,2};

void show_array(vector<int> nums){
    for (auto x:nums){
        cout << x << ", ";
    }
    cout << endl;
}

void selection_sort(vector<int> nums){
    int n = nums.size();
    for(int i=0; i<=n-1; i++){
        int temp = nums[i];          // temp variable for swapping
        int min_element = nums[i];   // set min_element as current element
        int min_index = i;           // set min_index
        for(int j=i; j<=n-1; j++){
            if (nums[j]<min_element){ 
                min_index = j;
                min_element = nums[j];
            }
        }
        nums[i] = nums[min_index];   // swap i to  min_index
        nums[min_index] = temp;
    }
    show_array(nums);

}

int main(){
    show_array(nums);
    selection_sort(nums);
    return 0;
}


/*
user@pc:~/ComputerScience/Algorithms/Sorting$ ./Selection_Sort 
6, 5, 7, 4, 8, 3, 1, 9, 2, 
1, 2, 3, 4, 5, 6, 7, 8, 9, 
*/
