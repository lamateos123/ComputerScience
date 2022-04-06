#include<iostream>

using namespace std;

/*

*/

bool isPerfectSquare(int num){
    bool ans = false;
    long long int squared;
    if (num == 1) return true;
    for (int i=0; i<num; i++){
        squared = i*i;
        if (squared == num) {
            ans = true;
            break;
            }
        else if (squared > num) {
            break;
        }
    }
    return ans;
}

int main(){
    int num;
    num = 1;
    cout << boolalpha << isPerfectSquare(num) << endl;
    return 0;
}