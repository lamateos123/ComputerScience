#include<iostream>
#include<vector>

using namespace std;

vector<int> A = {1,2,4,5,7,8,9,10,30,40,50,80,90,500,800,900};
int target = 3;

bool binary_search(vector<int> A, int target){
    int left = 0;
    int right = A.size();
    while(left<=right){
        int mid = (left+right)/2;
        cout << "target = " << target << " finding A[" << mid << "] = " << A[mid] << endl;
        if (target == A[mid]){
            return true;
        }
        else {
            if (A[mid] > target){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    }
    return false;
}

int main(){
    cout << boolalpha << binary_search(A, target);
}

/*
wj@lg:~/Desktop/ComputerScience/Algorithms/Search$ ./Binary_Search 
target = 2 finding A[8] = 30
target = 2 finding A[3] = 5
target = 2 finding A[1] = 2
true

wj@lg:~/Desktop/ComputerScience/Algorithms/Search$ ./Binary_Search 
target = 3 finding A[8] = 30
target = 3 finding A[3] = 5
target = 3 finding A[1] = 2
target = 3 finding A[2] = 4
false
*/