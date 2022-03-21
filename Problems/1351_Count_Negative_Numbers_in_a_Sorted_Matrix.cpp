#include<iostream>
#include<vector>

using namespace std;

/*
# 1351. Count Negative Numbers in a Sorted Matrix
'''
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and 
column-wise, return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
'''
*/

int countNegatives(vector<vector<int>> grid){
    int ans = 0;
    int c = grid.size();
    int r = grid[0].size();
    for (int i=c-1; i>-1; i--){
        for (int j=r-1; j>-1; j--){
            cout << grid[i][j];
            if (grid[i][j] >= 0){
                break;
            } else {
                ans += 1;
            }
        }
        cout << endl;
    }
    return ans;
}

int main(){
    vector<vector <int>> grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    cout << countNegatives(grid);
    return 0;
}
/*
~/Desktop/ComputerScience/Problems$ ./1351_Count_Negative_Numbers_in_a_Sorted_Matrix 
-3-2-1-1
-2-11
-11
-12
8
*/