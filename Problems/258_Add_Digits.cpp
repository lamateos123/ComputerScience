#include<iostream>
#include<string>

using namespace std;

int addDigits(int num){
    int ans = 0;
    string nums = to_string(num);
    string temp = "";
    while(true){
        for(auto s:nums){
            ans += int(s);
        }
        cout << ans << endl;
        temp = to_string(ans);
        if (temp.size() == 1){
            break;
        } else {
            ans = 0;
        }
    }
    return ans;
}

int main(){
    int num = 38;
    cout << addDigits(num);
    return 0;
}