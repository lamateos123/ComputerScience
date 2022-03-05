#include<iostream>
#include<string>

using namespace std;

int addDigits(int num){
    int ans;
    string nums = to_string(num);
    //cout << "nums" << nums << endl;
    while(true){
    //for (int i=0; i<10; i++){
        ans = 0;
        for(auto s:nums){
            ans += (s-'0');
            //cout << "ans" << ans << ", s" << s << endl;
        
        }
        //cout << ans << endl;
        nums = to_string(ans);
        //cout << "to_string(ans)" << nums << endl;
        if (nums.size() == 1){
            return ans;
        }
    }
    return 0;
}

int main(){
    int num = 38;
    cout << addDigits(num);
    return 0;
}

/*
~/Desktop/ComputerScience/Problems$ ./258_Add_Digits 
2
*/