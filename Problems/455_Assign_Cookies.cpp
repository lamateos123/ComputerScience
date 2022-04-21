#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*

*/

int assignCookies(vector<int> g, vector<int> s){
    int content = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    for (int i=0; i<s.size(); i++){
        if (content >= g.size()) break;
        if (s[i] >= g[content]) content++;
    }
    return content;
}

int main(){
    vector<int> g;
    vector<int> s;
    g = {1,2,3};
    s = {1,1};
    cout << assignCookies(g,s) << endl;

    g = {1,2};
    s = {1,2,3};
    cout << assignCookies(g,s) << endl;    
    return 0;
}