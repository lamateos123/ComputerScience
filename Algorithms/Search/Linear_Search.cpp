#include<iostream>
#include<vector>

using namespace std;

vector<int> A = {5,6,4,7,3,8,1,9,2};
int item = 3;

bool linear_search_unordered(vector<int> A, int item){
    for (auto x:A){
        if (x == item){
            return true;
        }
    }
    return false;
}

int main(){
    cout << boolalpha << linear_search_unordered(A,item);
}