#include<iostream>
#include<vector>

using namespace std;

/*
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints 
of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, 
such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1
*/

int mostWater(vector<int> height){
    int base = 0;
    int altura = 0;
    int area = 0;
    int max_area = 0;
    for (int i=0; i<height.size(); i++){
        for (int j=i+1; j<height.size(); j++){
            if ((i!=j) and (j>i)){
                base = j-i;
                altura = min(height[i],height[j]);
                area = base*altura;
                if (area > max_area) max_area = area;
            }
        }
    }
    return max_area;
}

int mostWater_improved(vector<int> height){
    int max_vol = 0;
    int cur_vol =0;
    int width = 0;
    int l = 0;
    int r = height.size()-1;

    while(l<r){
        width = r-l;
        cur_vol = min(height[l],height[r]) * width;
        max_vol = max(max_vol, cur_vol);
        if (height[l] < height[r]){
            l+=1;
        }else{
            r-=1;
        }
    }
    return max_vol;
}

int main(){
    vector<int> height;
    height = {1,8,6,2,5,4,8,3,7};

    //cout << mostWater(height) << endl;;
    cout << mostWater_improved(height) << endl;
    return 0;
}
/*
~/github/ComputerScience/Problems$ ./11_Container_With_Most_Water 
49
*/