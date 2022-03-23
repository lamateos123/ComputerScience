#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
# 1710. Maximum Units on a Truck
'''
You are assigned to put some amount of boxes onto one truck. You are given a 
2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

    numberOfBoxesi is the number of boxes of type i.
    numberOfUnitsPerBoxi is the number of units in each box of the type i.

You are also given an integer truckSize, which is the maximum number of boxes 
that can be put on the truck. You can choose any boxes to put on the truck as 
long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

Example 2:

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
'''
*/
struct Comparator {
    bool operator()(vector<int> const& p1, vector<int> const& p2) {
        return p1[1] > p2[1];
    }
};

int maxUnits(vector<vector<int>> boxTypes, int truckSize){
    int ans_units = 0;
    int ans_boxes = 0;
    int temp = 0;
    // sort by units
    sort(boxTypes.begin(), boxTypes.end(), Comparator());
    for (int i=0; i<boxTypes.size(); i++){
        for (int j=0; j<boxTypes[0].size(); j++){
            cout << boxTypes[i][j] << ",";
        }
        cout << endl;

    }

    int i = 0;
    while (ans_boxes <= truckSize){
        if (truckSize - ans_boxes >= boxTypes[i][0]) {
            ans_boxes += boxTypes[i][0];
            ans_units += boxTypes[i][0] * boxTypes[i][1];
        } else {
            temp = truckSize - ans_boxes;
            ans_boxes += temp;
            ans_units += temp * boxTypes[i][1];
        }
        i++;
        if ((truckSize - ans_boxes == 0) || (i >= boxTypes.size())){
            return ans_units;
        }
    }

    return 0;
}

int main(){
    vector<vector<int>> boxTypes = {{5,10},{2,5},{4,7},{3,9}};
    //cout << boxTypes[0][0];
    int truckSize = 10;
    cout << maxUnits(boxTypes, truckSize);
    return 0;
}