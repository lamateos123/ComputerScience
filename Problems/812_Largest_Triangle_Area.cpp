#include<iostream>
#include<vector>

using namespace std;

/*
# 812. Largest Triangle Area
'''
Formula of area of a triangle if coordinates are given
1/2(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))

Given an array of points on the X-Y plane points where points{i} = {xi, yi}, 
return the area of the largest triangle that can be formed by any three different 
points. Answers within 10-5 of the actual answer will be accepted.

Input: points = {{0,0},{0,1},{1,0},{0,2},{2,0}}
Output: 2.00000
Explanation: The five points are shown in the above figure. The red triangle is the largest.

Example 2:

Input: points = {{1,0},{0,0},{0,1}}
Output: 0.50000

'''
*/

int largestTA(vector<vector<int>> points){
    double area = 0;
    double  curr = 0;
    int n = points.size();
    for(int i=0;i<n; i++){
        int x1 = points[i][0];
        int y1 = points[i][1];
        for(int j=i+1; j<n;j++){
            int x2 = points[j][0];
            int y2 = points[j][1];
            for (int k=i+2;k<n;k++){
                int x3 = points[k][0];
                int y3 = points[k][1];
                curr = 0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
                curr = abs(curr);
                area = max(area,curr);
            }
        }
    }
    return area;
}

int main(){
    vector<vector<int>> points;
    points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout << largestTA(points) << endl;
    return 0;
}
