#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
# 1436. Destination City
'''
You are given the array paths, where paths[i] = [cityAi, cityBi] 
means there exists a direct path going from cityAi to cityBi. 
Return the destination city, that is, the city without any path 
outgoing to another city.

It is guaranteed that the graph of paths forms a line without any 
loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],
["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach 
"Sao Paulo" city which is the destination city. 
Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".

'''
*/

string destination(vector<vector<string>> paths){
    string ans;
    unordered_map<string,int> d;
    for (auto path:paths){
        //cout << path[1] << endl;
        d[path[1]] += 1;
    }
    for (auto path:paths){
        //cout << path[0] << endl;        
        if (d.find(path[0]) != d.end()){
            d[path[0]] += 1;
        }
    }
    for (auto i:d){
        if (i.second == 1){
            ans = i.first;
            break;
        }
    }
    return ans;
}

int main(){
    vector<vector<string>> paths = {{"B","C"},{"D","B"},{"C","A"}};
    cout << destination(paths) << endl;
    return 0;
}
