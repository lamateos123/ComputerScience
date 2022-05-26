#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*
int getIndex(vector<vector<int>> v, vector<vector<int>> k){
    auto it = find(v.begin(), v.end(), k);
    if (it != v.end()){ 
        int index = it -v.begin();
        return index;
    } else {
        return -1;
    }
}
*/

int edomino(vector<vector<int>> dominoes){
    unordered_map<int,int> d;
    vector<vector<int>> fichas = {{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{1,8},{1,9},{2,2},{2,3},{2,4},{2,5},{2,6},{2,7},{2,8},{2,9},{3,3},{3,4},{3,5},{3,6},{3,7},{3,8},{3,9},{4,4},{4,5},{4,6},{4,7},{4,8},{4,9},{5,5},{5,6},{5,7},{5,8},{5,9},{6,6},{6,7},{6,8},{6,9},{7,7},{7,8},{7,9},{8,8},{8,9},{9,9}};
    int c = 0;

    for (int i=0; i<dominoes.size(); i++){
        sort(dominoes[i].begin(),dominoes[i].end());        
    }

    for (auto ficha:dominoes){
        cout << ficha[0] << "," << ficha[1] << endl;
        for (int i=0; i<fichas.size(); i++){
            if ((ficha[0] == fichas[i][0]) && (ficha[1] == fichas[i][1])){
                d[i]++;
            }

        }
        //int x = getIndex(fichas,ficha);
        //d[x]++;
    }

    for (auto i:d){
        if (i.second > 0) c+=(i.second*(i.second-1)/2);
    }
    return c;

}

int main(){
    vector<vector<int>> dominoes;
    dominoes = {{1,2},{2,1},{3,4},{5,6}};
    cout << edomino(dominoes);

    dominoes = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    cout << edomino(dominoes);

    return 0;
}