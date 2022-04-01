#include<iostream>

using namespace std;

/*

*/

int bad;
int n;

bool isBadVersion(int x){
    bool ans = false;
    if (x == bad) ans = true;
    return ans;
}

int firstBad(int n){
    int l = 1;
    int r = n;
    long long int mid;
    while (l < r){
        mid = l + (r-l) / 2;
        if (isBadVersion(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    n = 5;
    bad = 4;
    cout << firstBad(n) << endl;
    return 0;
}