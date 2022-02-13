#include<iostream>
#include<vector>

using namespace std;

/*


# 1266. Minimum Time Visiting All Points
#-----------------------------------------
'''
On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. 
Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

    In 1 second, you can either:
        move vertically by one unit,
        move horizontally by one unit, or
        move diagonally sqrt(2) units (in other words, move one unit vertically then 
        one unit horizontally in 1 second).
    You have to visit the points in the same order as they appear in the array.
    You are allowed to pass through points that appear later in the order, but these 
    do not count as visits.

Example 1
Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
'''
*/

int visitTime(vector<vector<int>> &points){
    int ans = 0;
    int temp_x = 0;
    int max_x = 0;
    int temp_y = 0;
    int max_y = 0;
    vector<int>::const_iterator it;
    for (int i=0; i<points.size()-1; i++){
        temp_x = abs(points[i][0] - points[i+1][0]);
        temp_y = abs(points[i][1] - points[i+1][1]);
        if (temp_x>max_x) max_x = temp_x;
        if (temp_y>max_y) max_y = temp_y;
        if (max_x > max_y) {
            ans += max_x;
        } else {
            ans += max_y;
        }
    }
    return ans;
}

int main(){
    vector<vector <int>> points = {{1,1},{3,4},{-1,0}};
    cout << visitTime(points);
    return 0;
}
/*
~/github/ComputerScience/Problems$ ./1266_Minimum_Time_Visiting_All_Points 
7
*/