#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int highestAltitude(const vector<int> &gain){
    vector<int> ans = {0};
    int temp = 0;
    for (auto g:gain){
        temp += g;
        ans.push_back(temp);
    }
    for (auto a:ans){
        cout << a << ",";
    }
    cout << endl;

    sort (ans.begin(), ans.end());
    return ans[-1];
}

int highestAltitudeManualMax(const vector<int> &gain){
    vector<int> ans = {0};
    int temp = 0;
    int max = 0;
    for (auto g:gain){
        temp += g;
        ans.push_back(temp);
    }
    for (auto a:ans){
        if (a>max) max = a;
        cout << a << ",";
    }
    cout << endl;

    return max;
}

int highestAltitudeMax(const vector<int> &gain){
    vector<int> ans = {0};
    int temp = 0;
    int max = 0;
    for (auto g:gain){
        temp += g;
        ans.push_back(temp);
    }
    for (auto a:ans){
        cout << a << ",";
    }
    cout << endl;

    return *max_element(ans.begin(), ans.end());
}



int main(){
    vector<int> gain = {-5,1,5,0,-7};
    gain = {-4,-3,-2,-1,4,3,2};
    cout << highestAltitude(gain);
    //cout << highestAltitudeManualMax(gain);
    //cout << highestAltitudeMax(gain);
    return 0;
}

/*
~/github/ComputerScience/Problems$ ./1732_Find_the_Highest_Altitude 
0,-4,-7,-9,-10,-6,-3,-1,
0
*/